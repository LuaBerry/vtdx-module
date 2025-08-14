savedcmd_vtdx_module.mod := printf '%s\n'   vtdx_module.o | awk '!x[$$0]++ { print("./"$$0) }' > vtdx_module.mod
