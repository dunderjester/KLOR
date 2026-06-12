# MCU name
MCU = RP2040

# Bootloader selection
BOOTLOADER = rp2040

# Ignore some warnings during the build, likely to be fixed before RP2040 PR is merged
ALLOW_WARNINGS = yes

# LTO must be disabled for RP2040 builds
LTO_ENABLE = no

# PIO serial driver must be used on RP2040
SERIAL_DRIVER = vendor

# CONVERTER - if you use a listed MCU comment the first line and uncomment the appropiate line
#CONVERT_TO = promicro_rp2040
#CONVERT_TO = kb2040
#CONVERT_TO = blok
#CONVERT_TO = elite_pi

I2C_DRIVER_REQUIRED = yes

