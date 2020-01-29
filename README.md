# Lem_in

## Mondatory part:

The goal of this project is to find the quickest way to get n ants across the farm.
Quickest way means the solution with the least number of lines, respecting the output format requested below.
Obviously, there are some basic constraints. To be the first to arrive, ants will need to take the shortest path (and that isn’t necessarily the simplest). They will also need to avoid traffic jams as well as walking all over their fellow ants.
At the beginning of the game, all the ants are in the room ##start. The goal is
to bring them to the room ##end with as few turns as possible. Each room can
only contain one ant at a time. (except at ##start and ##end which can contain
as many ants as necessary.)


- The program will receive the data describing the ant farm from the standard output in the following format:

			number_of_ants
			the_rooms
			the_links

- Lines that start with ## are commands modifying the properties of the line that comes right after.

- The results on the standard output in the following format:

			number_of_ants
			the_rooms
			the_links
			Lx-y Lz-w Lr-o ...

		x, z, r represents the ants’ numbers (going from 1 to number_of_ants) and y, w, o represents the rooms’ names.

### ./lem-in < farm_map.txt | ./displayer/displayer

## Bonus:

- Vizualizer
- Extra Commands


## Owners:

- obelouch 1337
- ishaimou 1337


[project pdf!](https://github.com/XD-OB/lem_in/blob/master/lemin.pdf)
