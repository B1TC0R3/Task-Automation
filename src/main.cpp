//Copyright (C) 2023 Thomas Gingele

#include "common_headers.hpp"
#include "banner.hpp"
#include "formatting.hpp"
#include "config_reader.hpp"
#include "dotfile_handler.hpp"

std::string config_file = "resources/config.yml";

int main() {

    ConfigReader configReader;
    Config config = configReader.load(config_file);

    if (config.printBanner) {
        std::cout << FG_CYAN << BANNER << DEFAULT << std::endl;
    }

    std::cout << "Cloning into " << config.dotfiles.url << std::endl;
    DotfileHandler dotfile_handler (config.dotfiles);

    return 0;
}
