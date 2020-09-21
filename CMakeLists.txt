cmake_minimum_required(VERSION 3.17)
project(Proyecto_l)

set(CMAKE_CXX_STANDARD 17)

add_executable(Proyecto Main/main.cpp Productos/Producto.cpp Productos/Producto.h Productos/ProductoPerecedero.cpp Productos/ProductoPerecedero.h Auxiliares/Fecha.cpp Auxiliares/Fecha.h Productos/ProductoNoPerecedero.cpp Productos/ProductoNoPerecedero.h Monedero/MonederoElectronico.cpp Monedero/MonederoElectronico.h Dependencias_Maquina/IMaquinaAdministradora.h Dependencias_Maquina/IMaquinaVendedora.h Dependencias_Maquina/Maquina.cpp Dependencias_Maquina/Maquina.h Auxiliares/Nodo.cpp Auxiliares/Nodo.h Auxiliares/Lista.cpp Auxiliares/Lista.h Menus/MenuPrincipal.cpp Menus/MenuPrincipal.h Dependencias_Maquina/Maquina.cpp Menus/MenuAdministrador.cpp Menus/MenuAdministrador.h Menus/MenuCobro.cpp Menus/MenuCobro.h)