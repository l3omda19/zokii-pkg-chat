# Zokii Chat — PS4 Homebrew PKG

This is an independent PS4 homebrew application project.

Build target:
    Zokii-Chat.pkg

The GitHub Actions workflow uses the current OpenOrbis/orbis-ports build flow
and produces a PKG artifact.

Important:
- This is a standalone homebrew application, not a game overlay.
- A PKG is a package containing an eboot.bin and the required sce_sys metadata.
- A network chat needs a server endpoint; this starter includes a chat protocol
  core but does not hard-code a public server or credentials.
- The generated PKG is intended for a PS4 environment that permits homebrew
  package installation.

Build:
1. Create a GitHub repository.
2. Upload every file from this ZIP, including .github/workflows/build.yml.
3. Open Actions.
4. Run "Build Zokii Chat PKG".
5. Download the "Zokii-Chat-PKG" artifact.

The packaging structure follows the OpenOrbis homebrew requirements:
sce_sys/param.sfo + eboot.bin, with the package produced by the project tooling.
