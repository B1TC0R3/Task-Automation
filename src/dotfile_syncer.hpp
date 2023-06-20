# ifndef DOTFILE_SYNCER_H
# define DOTFILE_SYNCER_H

#include "common_headers.hpp"
#include "config_reader.hpp"

class DotfileSyncer {
    public:
        DotfileSyncer(Config config);
        void applyDotfiles();
        void backupDotfiles();
};

#endif
