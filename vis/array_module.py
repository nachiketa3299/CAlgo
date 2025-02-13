from manim import *
from dataclasses import dataclass, field

@dataclass
class ArrayConfig:
	box_size: float = 1
	box_space: float = 0.3
	box_stroke_width: float = 4
	box_text_width_ratio: float = 0.6

	idx_label_vspace: float = 0.2

	cont_color_on_min: ManimColor = TEAL_A
	cont_color_on_max: ManimColor = TEAL_D
	data: list = field(default_factory=lambda: [5250, 2, -32, -123, 22, 24, 1122])

	draw_placeholder: bool = True

@dataclass
class ArrayContainerConfig:
	box_size: float = 1
	box_stroke_width: float = 4
	box_text_width_ratio: float = 0.4
	box_fill_color: ManimColor = None

class ArrayContainer(VGroup):
	def __init__(self, value, config=ArrayContainerConfig(), **kwargs):
		super().__init__(**kwargs)
		self.config = config

		self.value = value # NOTE: this is not VGroup

		self.box = Square()
		self.box.side_length = self.config.box_size
		self.box.set_stroke(WHITE, self.config.box_stroke_width)
		self.box.set_fill(self.config.box_fill_color, opacity=0.7)

		self.value_text = Text(str(value))
		self.value_text.move_to(self.box.get_center())

		desired_text_width = self.box.width * self.config.box_text_width_ratio;

		self.value_text.scale_to_fit_width(desired_text_width)

		self.add(self.box, self.value_text)

class Array(VGroup):
	def __init__(self, config=ArrayConfig(), **kwargs):
		super().__init__(**kwargs)
		self.config = config

		self.unique_sorted_array = sorted(list(set(self.config.data)))
		self.color_map = color_gradient(
			[self.config.cont_color_on_min, self.config.cont_color_on_max], 
			len(self.unique_sorted_array)
		)

		# Create placeholders

		self.placeholders = VGroup()

		placeholder_line_opacity = 0.3 if self.config.draw_placeholder else 0

		for _ in self.config.data:
			placeholder = Square()
			placeholder.side_length = self.config.box_size * 1.2
			placeholder.set_stroke(opacity=placeholder_line_opacity)

			self.placeholders.add(placeholder)

		self.placeholders.arrange(RIGHT, buff=self.config.box_space)

		# Create containers & labels

		self.containers = VGroup()
		self.index_labels = VGroup()

		for idx, (value, placeholder) in enumerate(zip(self.config.data, self.placeholders)):
			# Create value container
			cont_config = ArrayContainerConfig(
				box_size=self.config.box_size, 
				box_stroke_width=self.config.box_stroke_width, 
				box_text_width_ratio=self.config.box_text_width_ratio,
				box_fill_color=self.get_color_of_value(value)
			)

			container = ArrayContainer(value, cont_config)
			container.move_to(placeholder.get_center())

			self.containers.add(container)

			# Create index label
			index_label = Text(f"[{idx}]")
			index_label.scale_to_fit_width(container.width * 0.5)
			index_label.next_to(placeholder, DOWN, buff=self.config.idx_label_vspace)

			self.index_labels.add(index_label)
		
		self.add(self.placeholders, self.containers, self.index_labels)

	def get_color_of_value(self, value):
		return self.color_map[self.unique_sorted_array.index(value)]
