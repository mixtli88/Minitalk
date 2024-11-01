
# # GREEN='\033[0;32m'
# # RED='\033[0;31m'
# # NC='\033[0m' 

# # touch Makefile
# # mkdir inc
# # mkdir src
# # mkdir lib
# # mkdir test

# # touch src/main.c
# # touch src/utils.c
# # touch src/parsing.c
# # touch src/init.c
# # touch src/main.c
# # touch inc/minitalk.h
# # echo "${GREEN}Project build successfully${NC}"

# # Colores
# GREEN='\033[0;32m'
# RED='\033[0;31m'
# NC='\033[0m'

# # Variable para rastrear si el script ha sido ejecutado antes
# create_files_and_dirs() {
#     mkdir -p inc src lib test
#     touch src/{main.c,utils.c,parsing.c,init.c}
#     touch inc/minitalk.h
# }
# # Comprueba si el script ya fue ejecutado
# if [ -s ".script_executed" ]; then
#     echo -e "${RED}Script ejecutado anteriormente.${NC}"
# else
#     create_files_and_dirs
#     echo -e "${GREEN}Project build successfully${NC}"
# fi
# if [ ! -f ".script_executed" ]; then
#     touch .script_executed
# fi

# # Función para crear archivos y directorios


# Colores
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m'

# Función para crear archivos y directorios
create_files_and_dirs() 
{
    mkdir inc
    mkdir src  
    mkdir lib 
    mkdir test
	touch Makefile

    touch src/{main.c}
    touch src/{utils.c}
    touch src/{utils.cc}
    touch src/{init.c}
    touch inc/minitalk.h
}

# Comprueba si el script ya fue ejecutado
if [ -s ".script_executed" ]; then
    echo "${RED}Script ejecutado anteriormente.${NC}"
else
    create_files_and_dirs
    echo "${GREEN}Project build successfully${NC}"
	echo "OK" > .script_executed
fi

# # Colores
# GREEN='\033[0;32m'
# RED='\033[0;31m'
# NC='\033[0m'

# # Función para crear archivos y directorios
# create_files_and_dirs() {
#     mkdir -p inc src lib test
#     touch src/{main.c,utils.c,parsing.c,init.c}
#     touch inc/minitalk.h
# }

# # Comprueba si el script ya fue ejecutado
# if [ -s ".script_executed" ]; then
#     echo -e "${RED}Script ejecutado anteriormente.${NC}"
# else
#     create_files_and_dirs
#     echo -e "${GREEN}Project build successfully${NC}"
# 	echo "OK" > .script_executed
# fi