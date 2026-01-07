-- prj/.nvim.lua (shared config for all subprojects)
return {
	compiler = "g++",
	std = "c++23",
	flags = {
		"-fdiagnostics-color=always",
		"-g",
		"-ggdb",
		"-pedantic-errors",
		"-Wall",
		"-Wshadow",
		"-Weffc++",
		"-Wextra",
		"-Wconversion",
		"-Wsign-conversion",
		"-Werror",
	},
	-- Dynamically detect .cpp files in the CURRENT project subdir (e.g., prj/001/)
	sources = function()
		local subdir = vim.fn.fnamemodify(vim.fn.expand("%:p"), ":h") -- Dir of current file
		return subdir .. "/*.cpp" -- All .cpp files in the subproject dir
	end,
}
