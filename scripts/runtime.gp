reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0-0.06):($2+0.001):2 with labels notitle ' ', \
'' using 3:xtic(1) with histogram title 'optimized'  , \
'' using ($0+0.2):($3+0.05):3 with labels notitle ' ', \
'' using 4:xtic(1) with histogram title 'hash_optimized' , \
'' using ($0+0.3):($4+0.0015):4 with labels notitle ' ' , \
'' using 5:xtic(1) with histogram title 'djb2hash_optimized' , \
'' using ($0+0.4):($5+0.005):5 with labels notitle ' '
