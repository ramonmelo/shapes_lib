# Config

$current_dir = @(pwd)
# $generator = "Visual Studio 16 2019"
# $arch = "x64"
# $generator_cfg = @"
# -G "$generator" -A $arch
# "@
$flags = "-DBUILD_SHARED_LIBS:BOOL=TRUE"
$target_dir = "_builds/shared"
$install_dir = "$current_dir\_install"
$config = "Debug"

# Clean
cmake --build $target_dir --target clean
# Config
cmake -S . -B $target_dir -G "Visual Studio 16 2019" -A x64 "$flags"
# Build
cmake --build $target_dir --config "$config"
# Install
cmake --install $target_dir --config "$config" --prefix "$install_dir"