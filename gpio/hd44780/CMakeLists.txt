add_executable(hd44780
hd44780.c
        )

# Pull in our pico_stdlib which pulls in commonly used features
target_link_libraries(hd44780 pico_stdlib)

# create map/bin/hex file etc.
pico_add_extra_outputs(hd44780)

# add url via pico_set_program_url
example_auto_set_url(hd44780)