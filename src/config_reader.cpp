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
    DotfileConfig dotfile_config;
    YAML::Node dotfile_yaml = this->yaml["dotfiles"];

    if (!dotfile_yaml) {
        return dotfile_config_fallback;
    }

    dotfile_config.use_git = this->getValue(dotfile_yaml["use-git"], false);
    dotfile_config.git_repository = this->getValue(dotfile_yaml["git-repository"], "");
    dotfile_config.clone_to = this->getValue(dotfile_yaml["clone-to"], "");

    //TODO: Implement yaml to vector conversion

    return dotfile_config;
}

template<typename Type>
Type ConfigReader::getValue(YAML::Node node, Type defaultValue) {
    if (node) {
        return node.as<Type>();
    }

    return defaultValue;
}
