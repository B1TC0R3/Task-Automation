#ifndef DOTFILE_HANDLER_H
#define DOTFILE_HANDLER_H

#include <git2.h>

#include "common_headers.hpp"
#include "config_reader.hpp"

class DotfileHandler {
    DotfileConfig config;
    git_repository *repo; 
    std::filesystem::copy_options cp_opt;

    public:
        DotfileHandler(DotfileConfig config);
        void cloneRepository();
        void backupDotfiles();
        void syncDotfiles();

        // SETTER
        void setDotfileConfig(DotfileConfig config);

    private:
        int handleGitAction(int status);
        void createDirectory(std::string path);
};

#endif
