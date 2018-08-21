# Aula-4-Desempenho

## Afinidade / AFFINITY ##
A afinidade de threads (Thread affinity ) restringe a execução de determinadas threads (unidades de execução virtual) a um subconjunto das unidades de processamento físico em um computador com multiprocessador. Dependendo da topologia da máquina, a afinidade de threads pode ter um efeito dramático na velocidade de execução de um programa.
Isso minimiza a migração de threads e o custo da troca de contexto entre os núcleos (cores). Ela também melhora a localidade dos dados e reduz o tráfego de coerência de cache entre os núcleos (ou processadores).
OpenMP tem a capacidade de vincular (bind) threads OpenMP a unidades de processamento físico. A interface é controlada usando uma variável de ambiente cujo nome depende do compilador em uso. Ex. para Intel use KMP_AFFINITY.
https://gcc.gnu.org/onlinedocs/libgomp/GOMP_005fCPU_005fAFFINITY.html#GOMP_005fCPU_005fAFFINITY

Exercício: [Multiplicação de matrizes](./profiling)
