Para compilar:
g++ -std=c++11 main.cpp -o main

Para executar:
./main

INSTRUÇÕES JSON:

É necessário registrar o de comandos por meio da linha:
"commands": 3
(substituindo 3 pelo número de comandos)

É necessário criar objetos (representando comandos) e numerá-los em ordem crescente

Os comandos serão lidos e executados nessa ordem

Em cada objeto deverá haver uma linha determinando o "shape"

Shapes
	- "line"
	- "circle"
	- "interpolate"

"line"
	deve ter "x1","y1" (ponto de partida da linha), "x2","y2" (ponto onde a linha termina)
	também pode conter a "thickness" (espessura) da linha, que por padrão é 1.

"circle"
	"x", "y" centro, "radius" raio

"interpolate"
	cXX - Onde XX indica o quadrante (0 = esquerda/baixo) (1 = direita cima)
		Ex: c01 quadrante inferior direito (nessa ordem)
		Cada quadrante será um objeto, devendo conter valores para "r" "g" e "b" entre 0 e 255
		Estes serão interpolados sobre toda a extensão da tela

EXEMPLO

{
    "commands":3,
    "1":{
        "shape":"interpolate",
        "c00":{
            "r":10,
            "g":50,
            "b":0
        },
        "c01":{
            "r":30,
            "g":250,
            "b":100
        },
        "c10":{
            "r":100,
            "g":100,
            "b":30
        },
        "c11":{
            "r":200,
            "g":0,
            "b":150
        }
    },
    "2":{
        "shape":"line",
        "x1":50,
        "y1":50,
        "x2":10,
        "y2":10,
        "thickness":2
    },
    "3":{
        "shape":"circle",
        "x":100,
        "y":50,
        "radius":4
    }

}