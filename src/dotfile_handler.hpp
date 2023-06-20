# ifndef DOTFILE_HANDLER_H
# define DOTFILE_HANDLER_H

#include "common_headers.hpp"
#include "config_reader.hpp"

class DotfileHandler {
    DotfileConfig dotfile_config;

    public:
        DotfileHandler(DotfileConfig dotfile_config);
};

#endif
