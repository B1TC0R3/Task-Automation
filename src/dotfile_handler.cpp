#include "dotfile_handler.hpp"

DotfileHandler::DotfileHandler(DotfileConfig config) {
    this->config = config;
    this->repo = NULL;
}

void DotfileHandler::setDotfileConfig(DotfileConfig config) {
    this->config = config;
}

int DotfileHandler::cloneRepository() {
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
    return status;
}

int DotfileHandler::handleGitAction(int status) {
    if (status != 0) {
        const git_error* e = git_error_last();
        std::cout << e->klass << " | " << e->message << std::endl;
    }

    return status;
}
