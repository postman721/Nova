# Nova (Qt 6)

Nova is a lightweight, classic radio-style volume control.

<img width="344" height="303" alt="Image" src="https://github.com/user-attachments/assets/3bce58cd-8a28-44a1-b22f-a5264cbd3381" />

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
