# Projeto orientado a objeto


## << Diagrama de Classes >>

<div align="center">
	<figure>
		<img src="img/Class_diagram_FPJ.png" 
			 width="100%" 
			 style="padding: 10px">
		<figcaption></figcaption>
	</figure>
</div>


<p>		O diagrama de classes apresentado contém 18 classes relacionadas por
herança e composição. Sendo que somente as classes relacionadas aos componentes
eletrônicos são ligadas as classes Filtro_ativo e Filtro_passivo por composição, 
visto que são as únicas que podem possuir mais de um objeto simultâneo. </p>

<p> 	No entanto, reconhecendo-se a complexidade do primeiro diagrama, um segundo
foi elaborado, objetivando mais simplicidade, porém com a desvantagem de sobrecarregar 
as classes com muitos métodos, além de que muitos atributos podem não ser usados e as
funções podem ficar mais complexas de implementar, visto que são mais genéricas. O diagrama
 de classe equivalente é apresentado abaixo:</p>

<div align="center">
	<figure>
		<img src="img/Class_diagram_FPJ_V2.png" 
			 width="100%" 
			 style="padding: 10px">
		<figcaption></figcaption>
	</figure>
</div>

## << Diagramas de Interação >>

### Diagrama de Sequência
<p>		O diagrama de sequência a seguir foi desenhado com base nas classes do primeiro
diagrama de classes apresentado. Portanto, pode ter sua dimensão horizontal dimunuida
com a adoção do segundo diagrama de classe, porém, um segundo desenho é desnecessário,
visto que, a execução de qualquer um dos diagramas produzem os mesmo resultado na tela
do usuário.</p>
 
<div align="center">
	<figure>
		<img src="img/Diagrama_de_sequencia_PJ.png" 
			 width="100%" 
			 style="padding: 10px">
		<figcaption></figcaption>
	</figure>
</div>

<p>
	O diagrama de sequência abaixo segue as classes do segundo diagrama de classes apresentado.
Percebe-se que, apesar da diferença de dimesões, a execução é a mesma.</p>

<div align="center">
	<figure>
		<img src="img/Diagrama_de_sequencia_PJ_V2.png" 
			 width="100%" 
			 style="padding: 10px">
		<figcaption></figcaption>
	</figure>
</div>


<div align="center">

[Retroceder](analise.md) | [Avançar](implementacao.md)

</div>