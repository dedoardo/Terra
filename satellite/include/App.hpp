#pragma once

// Satellite
#include <Visualization.hpp>
#include <Renderer.hpp>
#include <Graphics.hpp>
#include <Scene.hpp>
#include <Console.hpp>

// stdlib
#include <vector>
#include <memory>
#include <functional>

// The App is a container for Window, Presentation layers
// registers itself to the UI callbacks and passes events around
class App {
  public:
    App ( int argc, char** argv );
    ~App();

    int run ();

  private:
    int _boot();
    void _init_ui();
    void _init_cmd_map();

    void _shutdown();

    int _opt_set ( int opt, int value );
    int _opt_set ( int opt, const std::string& value );
    int _opt_set ( bool clear, std::function<int() > setter );

    void _clear();

    void _on_config_change ( bool clear );

    GFXLayer      _gfx;
    Scene         _scene;
    TerraRenderer _renderer;

    // Presentation
    Console     _console;
    Visualizer  _visualizer;

    // Callbacks
    using CommandMap = std::map<std::string, CommandCallback>;
    CommandMap      _c_map;
};