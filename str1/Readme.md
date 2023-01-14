This small project is about to implement running string visualization.

Make sure to install `gtk4` lib

For macos users: make sure you've installed *gmake* (gnu make utility), otherwise the build won't work(directories creation 
will have failed).

To clean up use `gmake clean`
To build use `gmake`, for a run use `gmake run`

To make sure, .vscode settings are corresponding to your host, run `pkg-config --libs gtk4`,
`pkg-config --cflags-only-I gtk4` and copy-paste them into settings file where applicable