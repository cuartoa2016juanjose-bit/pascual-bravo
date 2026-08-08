
#!/bin/bash
# threat_sim.sh — Simula un script malicioso (INOFENSIVO) y muestra cómo detectarlo

echo "[AMENAZA] Creando script sospechoso simulado..."

# Crear el "virus falso" — solo borra un archivo temporal (sin daño real)
cat > /tmp/virus_falso.sh << 'EOF'
#!/bin/sh
# SIMULACION: Este script imita comportamiento malicioso
echo "[VIRUS SIMULADO] Intentando modificar permisos..."
chmod 777 /tmp/test_victima.txt 2>/dev/null
echo "[VIRUS SIMULADO] Intentando eliminar archivo temporal..."
rm -f /tmp/test_victima.txt
echo "[VIRUS SIMULADO] Payload ejecutada (solo simulación, sin daño real)"
EOF

# Crear archivo víctima temporal
echo "datos sensibles simulados" > /tmp/test_victima.txt

echo "[DETECCION] Hash del script sospechoso ANTES de ejecutar:"
sha256sum /tmp/virus_falso.sh

echo ""
echo "[DETECCION] Permisos actuales del archivo sospechoso:"
ls -la /tmp/virus_falso.sh

echo ""
echo "[MITIGACION] En producción, bloquearíamos con: chmod 000 /tmp/virus_falso.sh"
echo "[MITIGACION] Y alertaríamos al sistema de monitoreo."
echo ""
echo "[SIM] Ejecutando payload inofensiva..."
sh /tmp/virus_falso.sh

echo ""
echo "[DETECCION] El archivo víctima fue eliminado: $(ls /tmp/test_victima.txt 2>&1)"
echo "[TIPO DE AMENAZA] Alteración — modifica/destruye datos del sistema"