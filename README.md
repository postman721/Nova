# Nova (Qt 6)

Nova is a lightweight, classic radio-style volume control.

## Dependencies

#### Required

qt6-base-dev

qt6-base-dev-tools

pulseaudio-utils 

pavucontrol



##### Debian: 

		sudo apt install qt6-base-dev, qt6-base-dev-tools pulseaudio-utils pavucontrol



## Build (qmake)
```bash
qmake
make
```

## Notes
- Uses `@DEFAULT_SINK@` (no hard-coded sink indexes).

Copyright 2026 JJ Posti <techtimejourney.net>
