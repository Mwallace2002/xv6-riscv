# INFORME T0 – Instalación y prueba de xv6 en macOS M1

## 1. Preparación del entorno
- Instalación de toolchain RISC-V y QEMU con Homebrew.
- Fork y clonación del repositorio vía GitHub CLI.
- Creación de la rama **t0-MWallace** para trabajar.

## 2. Compilación y ejecución de xv6
- Ejecución de `make qemu` dentro del repositorio clonado.
- xv6 se ejecutó correctamente en QEMU.
- Comandos probados dentro del sistema:
  - `ls`
  - `echo "Hola xv6"`
  - `cat README`

## 3. Evidencia visual
- Captura de pantalla: `docs/xv6-ok.png` mostrando el sistema xv6 corriendo y los comandos ejecutados.

## 4. Problemas encontrados y soluciones
- (Aquí describes si algo te falló, y cómo lo solucionaste)

## 5. Confirmación de funcionamiento
- xv6 compilado y funcionando en macOS M1 dentro de QEMU.
