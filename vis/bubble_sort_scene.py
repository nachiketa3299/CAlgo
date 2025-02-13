from manim import *
from array_module import Array, ArrayConfig

class BubbleSortScene(Scene):
	def construct(self):
		self.next_section(name="Prepare title")

		screen_width = self.camera.frame_width
		text_width_ratio = 0.8
		title_width = screen_width * text_width_ratio

		title = Text("Bubble Sort", width=title_width, slant=ITALIC, weight=BOLD)\
			.center()\
			.set_color_by_gradient(BLUE_C, WHITE, BLUE_C)

		sub_title = Text("Visualization").next_to(title, DOWN)

		title_group = VGroup(title, sub_title)

		self.play(Write(title_group))
		self.wait(1)

		self.next_section(name="Prepare on-screen components")

		section_title = Title("Bubble Sort (min)")

		self.play(
			Transform(title_group, section_title),
			run_time=2
		)

		# Array

		array_config = ArrayConfig(
			data=[5, 42, -3, 222, -55, 34, 2],
			draw_placeholder=False,
			cont_color_on_min=BLUE_A,
			cont_color_on_max=BLUE_E
		)

		array = Array(config=array_config)
		self.play(Write(array), run_time=6/4)
		self.next_section(name="Perform visualizing algorithm")

		for iteration in range(len(array.containers) - 1):
			for j in range(len(array.containers) - iteration - 1):
				self.play(
					Indicate(array.containers[j]), Indicate(array.containers[j + 1]),
					run_time=0.2
				)

				if (array.containers[j].value >= array.containers[j + 1].value):
					self.play(
						Wiggle(array.containers[j]), Wiggle(array.containers[j + 1]),
						run_time=1
					)

					self.play(
						CyclicReplace(array.containers[j], array.containers[j + 1]),
						run_time=0.2
					)

					array.containers[j], array.containers[j+1]\
						= array.containers[j+1], array.containers[j]

		self.wait(5)
	