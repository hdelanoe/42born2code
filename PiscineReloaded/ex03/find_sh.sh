find . -type f -name "*.sh" -print | sed 's/\.sh$//g' | rev | cut -f1 -d "/" | rev 
