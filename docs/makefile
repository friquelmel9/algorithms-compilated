help: ## Comando de ayuda
	@echo ""
	@echo "Regla                           Explicación"
	@echo "-----                           -----------"
	@awk 'BEGIN {FS = ":.*##"} /^[a-zA-Z0-9_-]+:.*##/ {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)
	@echo ""

requirements: ## Instala dependencias
	@echo "[+] Instalando dependencias..."

compile: ## Compila el archivo principal en pdf-latex
	@echo "[+] Compilando..."
	@pdflatex -interaction=nonstopmode main.tex > /dev/null 2>&1 || (echo "[!] Error al compilar"; exit 1)
	@biber main > /dev/null 2>&1
	@pdflatex -interaction=nonstopmode main.tex > /dev/null 2>&1 || (echo "[!] Error al compilar"; exit 1)
	@pdflatex -interaction=nonstopmode main.tex > /dev/null 2>&1 || (echo "[!] Error al compilar"; exit 1) 
	@$(MAKE) move

move: ## Mueve los archivos temporales a aux
	@find . -maxdepth 4 -type f ! -name '*.png' ! -name '*.tex' ! -name 'makefile' ! -name '*.pdf' \
		! -name 'README.md' ! -name 'author.tex' ! -name 'preamble.tex' ! -name 'references.bib' \
		! -name 'report.bcf-SAVE-ERROR' ! -name 'main.pdf' ! -name 'main.tex' ! -name 'sections' \
		-exec mv {} ./aux/ \; 2>/dev/null

clean: ## Limpia los archivos temporales en aux
	@rm -rf aux/*
