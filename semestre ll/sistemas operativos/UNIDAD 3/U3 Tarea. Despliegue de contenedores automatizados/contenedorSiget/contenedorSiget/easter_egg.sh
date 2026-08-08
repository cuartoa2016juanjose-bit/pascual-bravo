#!/bin/bash
# easter_egg.sh — Huevo de Pascua oculto. Se activa con la contraseña correcta.
# Uso: sh easter_egg.sh <clave>

CLAVE_SECRETA="siget2024"

if [ "$1" = "$CLAVE_SECRETA" ]; then
    echo ""
    echo "  ██████╗ ██╗ ██████╗ ███████╗████████╗"
    echo "  ██╔══██╗██║██╔════╝ ██╔════╝╚══██╔══╝"
    echo "  ╚█████╔╝██║██║  ███╗█████╗     ██║   "
    echo "  ██╔══██╗██║██║   ██║██╔══╝     ██║   "
    echo "  ██████╔╝██║╚██████╔╝███████╗   ██║   "
    echo ""
    echo "  🐣 Encontraste el huevo de Pascua del SIGET!"
    echo "  Módulo secreto de auditoría activo."
    echo "  Desarrollado con amor por el equipo SIGET 🚦"
    echo ""
else
    echo "[ERROR] Clave incorrecta. Acceso denegado."
fi 
