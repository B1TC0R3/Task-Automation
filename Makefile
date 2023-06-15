# Application Name
application_name = system-manager

# Configuration
main_file   = main.cpp
source_dir  = ./src
build_dir   = ./bin
entry_point = $(source_dir)/$(main_file)
application_path = $(build_dir)/$(application_name)

build:
	- mkdir $(build_dir)
	g++ $(entry_point) -o $(application_path)

test:
	g++ -fsyntax-only $(entry_point)	

