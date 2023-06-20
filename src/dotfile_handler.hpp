#ifndef DOTFILE_HANDLER_H
#define DOTFILE_HANDLER_H

#include <git2.h>

#include "common_headers.hpp"
#include "config_reader.hpp"

class DotfileHandler {
    DotfileConfig config;
    git_repository *repo; 

    public:
        DotfileHandler(DotfileConfig config);
        int cloneRepository();

        // SETTER
        void setDotfileConfig(DotfileConfig config);

    private:
        int handleGitAction(int status);
};

#endif
