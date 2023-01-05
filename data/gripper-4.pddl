(define (problem griper-4)
	(:domain gripper)

	(:objects
		rooma roomb - room
		ball1 ball2 ball3 ball4 - ball
		left right - gripper
	)

	(:init
		(free left)
		(free right)
		; (not (carry ball3 right))
		; (not (carry ball1 right))
		; (not (carry ball2 left))
		(at-robby roomb)
		(at ball1 rooma)
		(at ball2 rooma)
		(at ball3 rooma)
		(at ball4 rooma)
		(not (at ball1 roomb))
		(not (at ball2 roomb))
		(not (at ball3 roomb))
		(not (at ball4 roomb))
	)

	(:goal
		(and
			(at ball1 roomb)
			(at ball2 roomb)
			(at ball3 roomb)
			(at ball4 roomb)
			(at-robby roomb)
		)
	)
)