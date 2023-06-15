#include "common_headers.h"
#include "banner.h"
#include "formatting.h"
#include "config_reader.h"

int main() {
    std::cout << FG_CYAN << BANNER << DEFAULT << std::endl;
    return 0;
}
