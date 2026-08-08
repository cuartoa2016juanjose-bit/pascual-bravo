#!/bin/sh
# setup.sh — Crea usuario limitado para el SIGET

echo "[SIGET] Creando usuario operador..."

# En Alpine se usa addgroup y adduser asi:
addgroup -S siget_group
adduser -S -D -G siget_group -h /siget -s /bin/sh siget_op

# Asignar directorios al usuario
chown -R siget_op:siget_group /siget
chmod 750 /siget

# Crear archivo de configuración simulado
echo "SIGET_VERSION=1.0" > /siget/config/sistema.conf
echo "MODO=produccion" >> /siget/config/sistema.conf
chown siget_op:siget_group /siget/config/sistema.conf
chmod 640 /siget/config/sistema.conf

echo "[SIGET] Usuario siget_op creado correctamente."
echo "[SIGET] Directorio de trabajo: /siget"