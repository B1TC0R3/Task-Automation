#include "dotfile_handler.hpp"

DotfileHandler::DotfileHandler(DotfileConfig config) {
    this->config = config;
    this->repo = NULL;
    this->cp_opt = std::filesystem::copy_options::update_existing
                 | std::filesystem::copy_options::recursive
                 | std::filesystem::copy_options::recursive;
}

void DotfileHandler::setDotfileConfig(DotfileConfig config) {
    this->config = config;
}

void DotfileHandler::cloneRepository() {
    git_libgit2_init();

    int status = this->handleGitAction(
        git_clone(
            &this->repo,
            this->config.url.c_str(),
            this->config.clone_to.c_str(),
            NULL
        )
    );

    git_libgit2_shutdown();
}

void DotfileHandler::backupDotfiles() {
    for (int i = 0; i < this->config.file_bindings.size(); i++) {
        this->createDirectory(config.file_bindings.at(i).to);

        std::filesystem::copy(
            config.file_bindings.at(i).from,
            config.file_bindings.at(i).to,
            this->cp_opt
        );
    }
}

int DotfileHandler::handleGitAction(int status) {
    if (status != 0) {
        const git_error* e = git_error_last();
        std::cout << e->klass << " | " << e->message << std::endl;
    }

    return status;
}

void DotfileHandler::createDirectory(std::string path) {
    std::string partial_path;

    if (access(path.c_str(), F_OK) == 0) {
        return;
    }

    for (int i = 0; i < path.size(); i++) {
        if (path.at(i) == '/' && partial_path.size() != 0) {
            std::filesystem::create_directory(partial_path);
        } 

        partial_path += path.at(i);
    }
}
