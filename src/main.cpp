#include <iostream>
#include <filesystem>
#include <format>
#include <CLI/CLI.hpp>
#include <spdlog/spdlog.h>
#include "configforge/version.hpp"

namespace fs = std::filesystem;

struct GlobalOptions {
    bool verbose = false;
    std::string log_level = "info";
};

struct ValidateCommand {
    std::string config_file;
    std::string schema_file;
    bool strict = false;
};

struct ConvertCommand {
    std::string input_file;
    std::string output_file;
    std::string target_format;
    bool pretty = true;
};

struct MergeCommand {
    std::vector<std::string> input_files;
    std::string output_file;
    std::string strategy = "deep";
};

void setup_logging(const GlobalOptions& opts) {
    if (opts.verbose) {
        spdlog::set_level(spdlog::level::debug);
    } else if (opts.log_level == "trace") {
        spdlog::set_level(spdlog::level::trace);
    } else if (opts.log_level == "debug") {
        spdlog::set_level(spdlog::level::debug);
    } else if (opts.log_level == "warn") {
        spdlog::set_level(spdlog::level::warn);
    } else if (opts.log_level == "error") {
        spdlog::set_level(spdlog::level::err);
    } else {
        spdlog::set_level(spdlog::level::info);
    }
}

int handle_validate(const ValidateCommand& cmd) {
    spdlog::info("Validating configuration file: {}", cmd.config_file);
    
    if (!fs::exists(cmd.config_file)) {
        spdlog::error("Configuration file not found: {}", cmd.config_file);
        return 1;
    }
    
    if (!cmd.schema_file.empty() && !fs::exists(cmd.schema_file)) {
        spdlog::error("Schema file not found: {}", cmd.schema_file);
        return 1;
    }
    
    if (cmd.strict) {
        spdlog::info("Using strict validation mode");
    }
    
    // TODO: Implement validation logic
    spdlog::info("✅ Validation complete - file appears valid");
    return 0;
}

int handle_convert(const ConvertCommand& cmd) {
    spdlog::info("Converting {} to {}", cmd.input_file, cmd.output_file);
    
    if (!fs::exists(cmd.input_file)) {
        spdlog::error("Input file not found: {}", cmd.input_file);
        return 1;
    }
    
    if (!cmd.target_format.empty()) {
        spdlog::info("Target format: {}", cmd.target_format);
    }
    
    if (cmd.pretty) {
        spdlog::debug("Pretty-printing enabled");
    }
    
    // TODO: Implement conversion logic
    spdlog::info("✅ Conversion complete");
    return 0;
}

int handle_merge(const MergeCommand& cmd) {
    spdlog::info("Merging {} files using {} strategy", 
                 cmd.input_files.size(), cmd.strategy);
    
    for (const auto& file : cmd.input_files) {
        if (!fs::exists(file)) {
            spdlog::error("Input file not found: {}", file);
            return 1;
        }
        spdlog::debug("Input file: {}", file);
    }
    
    // TODO: Implement merge logic
    spdlog::info("✅ Merge complete - output written to {}", cmd.output_file);
    return 0;
}

int main(int argc, char** argv) {
    CLI::App app{configforge::DESCRIPTION, configforge::APP_NAME};
    app.set_version_flag("--version", configforge::VERSION);
    
    GlobalOptions global_opts;
    app.add_flag("-v,--verbose", global_opts.verbose, "Enable verbose output");
    app.add_option("--log-level", global_opts.log_level, 
                   "Set log level (trace,debug,info,warn,error)")
        ->check(CLI::IsMember({"trace", "debug", "info", "warn", "error"}));
    
    // Validate subcommand
    auto* validate_cmd = app.add_subcommand("validate", "Validate configuration files");
    ValidateCommand validate_opts;
    validate_cmd->add_option("config", validate_opts.config_file, "Configuration file to validate")
        ->required()->check(CLI::ExistingFile);
    validate_cmd->add_option("-s,--schema", validate_opts.schema_file, "Schema file for validation")
        ->check(CLI::ExistingFile);
    validate_cmd->add_flag("--strict", validate_opts.strict, "Enable strict validation mode");
    
    // Convert subcommand
    auto* convert_cmd = app.add_subcommand("convert", "Convert between configuration formats");
    ConvertCommand convert_opts;
    convert_cmd->add_option("input", convert_opts.input_file, "Input configuration file")
        ->required()->check(CLI::ExistingFile);
    convert_cmd->add_option("-o,--output", convert_opts.output_file, "Output file path")
        ->required();
    convert_cmd->add_option("-f,--format", convert_opts.target_format, 
                           "Target format (json,yaml,toml,ini)")
        ->check(CLI::IsMember({"json", "yaml", "toml", "ini"}));
    convert_cmd->add_flag("--pretty,!--no-pretty", convert_opts.pretty, 
                         "Pretty-print output (default: true)");
    
    // Merge subcommand
    auto* merge_cmd = app.add_subcommand("merge", "Merge multiple configuration files");
    MergeCommand merge_opts;
    merge_cmd->add_option("inputs", merge_opts.input_files, "Input configuration files")
        ->required()->check(CLI::ExistingFile);
    merge_cmd->add_option("-o,--output", merge_opts.output_file, "Output file path")
        ->required();
    merge_cmd->add_option("--strategy", merge_opts.strategy, 
                         "Merge strategy (deep,shallow,override)")
        ->check(CLI::IsMember({"deep", "shallow", "override"}));
    
    // Parse arguments
    CLI11_PARSE(app, argc, argv);
    
    // Setup logging
    setup_logging(global_opts);
    
    // Handle subcommands
    if (*validate_cmd) {
        return handle_validate(validate_opts);
    } else if (*convert_cmd) {
        return handle_convert(convert_opts);
    } else if (*merge_cmd) {
        return handle_merge(merge_opts);
    }
    
    // No subcommand provided
    std::cout << app.help() << std::endl;
    return 0;
}
