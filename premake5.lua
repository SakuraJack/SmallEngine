workspace "SmallEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "SmallEngine/ext/GLFW/include"

include "SmallEngine/ext/GLFW"

project "SmallEngine"
    location "SmallEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "sepzh.h"
    pchsource "SmallEngine/src/sepzh.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
		"%{prj.name}/ext/spdlog/include",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SE_PLATFORM_WINDOWS",
            "SE_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "SE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SE_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "SmallEngine/src",
        "SmallEngine/ext/spdlog/include",
    }

    links
    {
        "SmallEngine"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SE_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "SE_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "SE_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SE_DIST"
        optimize "On"