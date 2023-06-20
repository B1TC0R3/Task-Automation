//Copyright (C) 2023 Thomas Gingele

#include "config_reader.hpp"

DotfileConfig dotfile_config_fallback = DotfileConfig {
    false,
    "",
    "",
    std::vector<FileBinding>(),
};

Config ConfigReader::load(std::string file) {
    std::ifstream filestream(file);
    std::stringstream buffer;

    if (access(file.c_str(), F_OK) == -1) {
        throw std::runtime_error("Unable to read config file from '" + file + "'!");
    }

    buffer << filestream.rdbuf();
    this->yaml = YAML::Load(buffer.str());

    return this->convertYamlToStruct();
}

Config ConfigReader::convertYamlToStruct() {
    Config config;

    config.printBanner = this->getValue<bool>(this->yaml["printBanner"], true);
    config.dotfiles = this->parseDotfileConfig();

    return config;
}

DotfileConfig ConfigReader::parseDotfileConfig() {
    DotfileConfig dotfile_config = dotfile_config_fallback;

    YAML::Node dotfile_yaml = this->yaml["dotfiles"];
    YAML::Node filebind_yaml = dotfile_yaml["file-bindings"];

    if (!dotfile_yaml) {
        return dotfile_config_fallback;
    }

    dotfile_config.use_git = this->getValue<bool>(dotfile_yaml["use-git"], false);
    dotfile_config.url = this->getValue<std::string>(dotfile_yaml["url"], "");
    dotfile_config.clone_to = this->getValue<std::string>(dotfile_yaml["clone-to"], "");

    for (int i = 0; i < filebind_yaml.size(); i++) {
        dotfile_config.file_bindings.push_back(
            FileBinding {
                filebind_yaml[i]["from"].as<std::string>(),
                filebind_yaml[i]["to"].as<std::string>()
            }
        );
    }

    return dotfile_config;
}

template<typename Type>
Type ConfigReader::getValue(YAML::Node node, Type defaultValue) {
    if (node) {
        return node.as<Type>();
    }

    return defaultValue;
}
