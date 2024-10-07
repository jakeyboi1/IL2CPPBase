# IL2CPPBase
> IL2CPPBase is a Visual Studio project that serves as a base for modding IL2CPP Unity games. It provides an efficient and developer-friendly way to interact with Unity games by using `GetProcAddress` on exported Unity IL2CPP functions to then call game functions.

## Features
- **Dynamic Function Access:** Utilizes `GetProcAddress` to call IL2CPP functions, providing dynamic function calling.
- **Simple API:** Includes an easy-to-use class, to streamline the modding process.
- **Developer Experience:** Aims to enhance the ease of development for working on IL2CPP games.

## Installation
- Download the code zip, and run the projects .sln file
- Build the project and then use a software like ProcessHacker to inject the built .dll

## Example Usage
The base itself when you download has a built in example of how to use it. The built in example will spam change the games Field Of View.

## Contributions
Contributions are welcome! If you'd like to contribute, feel free to fork the repository and create a pull request.

## TODO
- Investigate a way to avoid needing to import headers from the Unity Engine.
- Rebuild the base Unity classes like UnityEngine to allow for easier use instead of getting each function and class individually. (This obviously will only apply to base unity functions as each game has their own classes)
- Investigate building a .exe that will inject every .dll inside of a folder named IL2CPPMods in a games base directory to essentially build a mod loader that injects .dll files built with this base.

## Credits:
- [Axxo](https://www.youtube.com/@axxo1337)
