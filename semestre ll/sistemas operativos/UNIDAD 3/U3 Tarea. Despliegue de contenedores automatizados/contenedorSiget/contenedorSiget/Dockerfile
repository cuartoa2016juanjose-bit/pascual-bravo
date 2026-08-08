# Base: Alpine Linux — ligero (~5MB), seguro, ideal para contenedores de producción
FROM alpine:3.19

# Metadatos
LABEL maintainer="SIGET-Team" description="Módulo prototipo SIGET"

# Instalar dependencias mínimas
RUN apk update && apk add --no-cache \
    bash \
    shadow \
    openssl \
    curl \
    && rm -rf /var/cache/apk/*

# Crear directorios del sistema
RUN mkdir -p /scripts /siget/logs /siget/config /siget/data

# Copiar scripts al contenedor
COPY setup.sh /scripts/setup.sh
COPY crypto.sh /scripts/crypto.sh
COPY easter_egg.sh /scripts/easter_egg.sh
COPY threat_sim.sh /scripts/threat_sim.sh

# Proteger scripts: solo root puede ejecutarlos (rwxr-x---)
RUN chmod 750 /scripts/*.sh

# Ejecutar configuración inicial
RUN sh /scripts/setup.sh

# Cambiar a usuario limitado

WORKDIR /siget

CMD ["/bin/sh"] 
