workspace "DxStudy"

	configurations
	{
		"Debug",
		"Release"
	}

	platforms 
	{ 
		"Win32", 
		"Win64"
	}

filter { "platforms:Win32" }
    system "Windows"
    architecture "x86"
	vectorextensions "SSE2"

filter { "platforms:Win64" }
    system "Windows"
    architecture "x64"

filter "configurations:Debug"
	defines "DEBUG"
	symbols "On"

filter "configurations:Release"
	defines "RELEASE"
	optimize "On"


filter "system:windows"
	cppdialect "C++17"
	systemversion "latest"
		


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Chapter01_VectorAlgebra"
	location "%{prj.name}"
	kind "ConsoleApp"
	language "C++"

	targetdir ("Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("Intermediate/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/Source/**.h",
		"%{prj.name}/Source/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/Source"
	}

