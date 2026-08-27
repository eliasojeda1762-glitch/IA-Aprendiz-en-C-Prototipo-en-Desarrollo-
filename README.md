[msg-Code.md](https://github.com/user-attachments/files/31498785/msg-Code.md)
# 🤖 IA Aprendiz en C (Prototipo en Desarrollo)

Un sistema de adquisición de conocimiento conversacional escrito en C puro. El programa busca conceptos aprendidos en almacenamiento local; si no conoce una palabra, se la enseña el usuario y la guarda automáticamente en disco para recordarla en ejecuciones futuras.

> ⚠️ **Estado del proyecto:** En desarrollo activo (Versión inicial / Experimental). Se agregarán mejoras de memoria, optimizaciones y análisis de texto.

---

## ✨ Características actuales
* **Aprendizaje dinámico:** Solicita explicaciones sobre términos desconocidos y los almacena.
* **Soporte para sinónimos:** Permite asociar palabras parecidas a un mismo concepto usando `strstr()`.
* **Persistencia en disco:** Creación automática de directorio (`base_datos/`) y almacenamiento con delimitadores (`|`) para evitar corrupción de datos.
* **Normalización:** Convierte el texto de entrada a minúsculas automáticamente.
* **Búferes protegidos:** Control contra desbordamientos de memoria (*buffer overflow*).

---

## 🚀 Próximas actualizaciones (Roadmap)
- [ ] Implementar borrado y edición de conceptos desde un menú principal.
- [ ] Búsqueda por coincidencia aproximada (distancia Levenshtein para errores de ortografía).
- [ ] Integración experimental de conectividad web con `libcurl`.

---

## 🛠️ Compilación y Ejecución

```bash
# Compilar con GCC
gcc main.c -o ia_aprendiz

# Ejecutar
./ia_aprendiz
