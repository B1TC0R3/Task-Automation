//Copyright (C) 2023 Thomas Gingele

#include "common_headers.h"
#include "banner.h"
#include "formatting.h"
#include "config_reader.h"

std::string config = "resources/config.yml";

int main() {
    std::cout << FG_CYAN << BANNER << DEFAULT << std::endl;

    ConfigReader cr;
    cr.load(config);

    return 0;
}
