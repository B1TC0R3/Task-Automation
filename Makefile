# Application Name
application_name = system-manager

# Configuration
objects   = src/main.cpp src/config_reader.cpp
libraries = -lyaml-cpp
source_dir  = ./src
build_dir   = ./bin
application_path = $(build_dir)/$(application_name)

build:
	- mkdir $(build_dir)
	g++ $(libraries) $(objects) -o $(application_path)

test:
	g++ -fsyntax-only $(entry_point)	

