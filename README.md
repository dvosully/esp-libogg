# esp-libogg

This repository creates an ESP32 component which provides the original OGG code
for the ESP32. It includes the original ogg reference library as a submodule.

### Usage
This repository can be added as submodule to any valid ESP32 component directory.
The easiest way to do this is to create a `component/` directory in the root
of an ESP project, using `git submodule add` followed by
`git submodule update --init --recursive` to clone this repo into there,
and to ensure that this new component is recognized via `make list-components`.

After adding this component to the build configuration, the "ogg/ogg.h" file
can be included. All OGG decoder and encoder methods are available, consult the
[OGG documentation](https://xiph.org/ogg/doc/libogg/overview.html) for examples.

### Demo
To build a demo application with the ESP32, simply:
- Clone this repository
- Open an ESP-IDF console
- `cd` to `./esp-libogg/example`
- Run `idf.py build`
- Flash the resulting code to your processor and observe.

