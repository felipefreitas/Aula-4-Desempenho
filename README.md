# Aula-4-Desempenho
<!-- TODO:  -->
## Aulas da disciplina Laboratório de Introdução à Programação Paralela ##
*Desempenho. Dependências de dado. Classificação. Lei de Amdahl. Profilers: gprof. Ferramentas para análise de desempenho: Intel VTune Analyzer. GnuPlot

## Afinidade / AFFINITY ##
A afinidade de threads (Thread affinity ) restringe a execução de determinadas threads (unidades de execução virtual) a um subconjunto das unidades de processamento físico em um computador com multiprocessador. Dependendo da topologia da máquina, a afinidade de threads pode ter um efeito dramático na velocidade de execução de um programa.
Isso minimiza a migração de threads e o custo da troca de contexto entre os núcleos (cores). Ela também melhora a localidade dos dados e reduz o tráfego de coerência de cache entre os núcleos (ou processadores).
OpenMP tem a capacidade de vincular (bind) threads OpenMP a unidades de processamento físico. A interface é controlada usando uma variável de ambiente cujo nome depende do compilador em uso. Ex. para Intel use KMP_AFFINITY.
https://gcc.gnu.org/onlinedocs/libgomp/GOMP_005fCPU_005fAFFINITY.html#GOMP_005fCPU_005fAFFINITY

> Exercício. Execute o programa na semana anterior com um número de steps 1000 vezes superior. Abra o terminal e execute o comando top configurado para ver as threads. Modifique o parâmetro de afinidade do programa e veja como se comporta.

## GnuPlot
[GnuPlot](http://gnuplot.info/): uma ferramenta open-source e free para criar gráficos 2D e 3D. 

Links úteis:
- Manual: http://gnuplot.info/docs_5.0/gnuplot.pdf
Demos: 
- average: http://gnuplot.sourceforge.net/demo_5.0/running_avg.html
- errorbars: http://gnuplot.sourceforge.net/demo_5.0/fit.html



Classificação de dependências de dado: Uma dependência de dado é chamada de *loop carried* se as duas expressões envolvidas na dependência ocorrem em diferentes iterações do laço.

## [Profiling](./profiling)

---

> Exercício: Para a próxima aula trazer implementado um programa para Multiplicação de matrizes
