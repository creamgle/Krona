workspace "Krona_Workspace"
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"

Includes = { }
Includes["Krona"] = "%{wks.location}/Krona/src"

include "Krona/vendor/glfw"
include "Krona/vendor/glad"

include "Krona"
include "Game"