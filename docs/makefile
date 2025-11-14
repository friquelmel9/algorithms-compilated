help: ## Comando de ayuda
	@echo ""
	@echo "Regla                           Explicación"
	@echo "-----                           -----------"
	@awk 'BEGIN {FS = ":.*##"} /^[a-zA-Z0-9_-]+:.*##/ {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}' $(MAKEFILE_LIST)
	@echo ""

requirements: ## Instala dependencias
	@echo "[+] Instalando dependencias..."

compile: clean ## Compila el archivo principal en pdf-latex
	@echo "[+] Compilando..."
	@pdflatex -shell-escape -interaction=nonstopmode main.tex > /dev/null 2>&1 || (echo "[!] Error al compilar"; exit 1)
	@biber main > /dev/null 2>&1
	@pdflatex -shell-escape -interaction=nonstopmode main.tex > /dev/null 2>&1 || (echo "[!] Error al compilar"; exit 1)
	@pdflatex -shell-escape -interaction=nonstopmode main.tex > /dev/null 2>&1 || (echo "[!] Error al compilar"; exit 1) 
	@$(MAKE) move

move: ## Mueve los archivos temporales a aux
	@mkdir -p aux
	@find . -maxdepth 4 -type f \( \
		-name '*.aux' -o \
		-name '*.bbl' -o \
		-name '*.bcf' -o \
		-name '*.blg' -o \
		-name '*.out' -o \
		-name '*.toc' -o \
		-name '*.run.xml' -o \
		-name '*.log' \
	\) -exec mv -f {} aux/ \;

clean: ## Limpia los archivos temporales en aux
	@rm -rf aux/*
