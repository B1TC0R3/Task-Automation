//Copyright (C) 2023 Thomas Gingele

#include "common_headers.hpp"
#include "banner.hpp"
#include "formatting.hpp"
#include "config_reader.hpp"

std::string config_file = "resources/config.yml";

int main() {

    ConfigReader configReader;
    Config config = configReader.load(config_file);

    if (config.printBanner) {
        std::cout << FG_CYAN << BANNER << DEFAULT << std::endl;
    }

    return 0;
}
