#!/bin/bash
# crypto.sh — Validación de integridad con SHA256 (simula protección de componentes SIGET)

echo "[CRYPTO] Generando archivo de configuración crítica..."
echo "trafico_sensores=activo" > /siget/config/critico.conf
echo "semaforos_zona1=online" >> /siget/config/critico.conf

echo "[CRYPTO] Calculando hash SHA256 del archivo..."
HASH=$(sha256sum /siget/config/critico.conf)
echo "$HASH" > /siget/config/critico.conf.sha256
echo "Hash generado: $HASH"

echo ""
echo "[CRYPTO] Verificando integridad..."
sha256sum -c /siget/config/critico.conf.sha256 && echo "[OK] Integridad verificada." || echo "[ALERTA] Archivo modificado!"

echo ""
echo "[CRYPTO] Simulando alteración del archivo..."
echo "DATOS_MALICIOSOS" >> /siget/config/critico.conf

echo "[CRYPTO] Verificando de nuevo tras alteración..."
sha256sum -c /siget/config/critico.conf.sha256 && echo "[OK]" || echo "[ALERTA] Integridad comprometida — archivo alterado!" 
