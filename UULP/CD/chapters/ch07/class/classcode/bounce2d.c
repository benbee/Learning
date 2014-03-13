#define	_VA_LIST		/* this keeps gcc's va_list from conflicting */
				/* with the stdarg.h va_list		*/
#include	<curses.h>
#include	<signal.h>


/*
 *	bounce2d 1.0	
 *
 *	bounce a character (default is *) around the screen
 *	defined by some parameters
 *
 *	user input:
 *		 	s slow down x component, S: slow y component
 *		 	f speed up x component,  F: speed y component
 *			Q quit
 *
 *	blocks on read, but timer tick sets SIGALRM which are caught
 *	by ball_move
 */

#include	"bounce.h"

struct ppball the_ball ;

/**
 **	the main loop
 **/

main()
{
	int	c;

	set_up();

	while ( ( c = getchar()) != 'Q' ){
		if ( c == 'f' )	     the_ball.x_ttm--;
		else if ( c == 's' ) the_ball.x_ttm++;
		else if ( c == 'F' ) the_ball.y_ttm--;
		else if ( c == 'S' ) the_ball.y_ttm++;
	}

	wrap_up();
}


set_up()
/*
 *	init structure and other stuff
 */
{
	void	ball_move();

	the_ball.y_pos = Y_INIT;
	the_ball.x_pos = X_INIT;
	the_ball.y_ttg = the_ball.y_ttm = Y_TTM ;
	the_ball.x_ttg = the_ball.x_ttm = X_TTM ;
	the_ball.y_dir = 1  ;
	the_ball.x_dir = 1  ;
	the_ball.symbol = DFL_SYMBOL ;

	initscr();
	noecho();
	crmode();

	signal( SIGINT , SIG_IGN   );
	put_a_char( the_ball.y_pos, the_ball.x_pos, the_ball.symbol  );
	refresh();
	
	signal( SIGALRM, ball_move );
	set_ticker( 1000 / TICKS_PER_SEC );	/* send millisecs per tick */
}

wrap_up()
{

	set_ticker( 0 );
	endwin();		/* put back to normal	*/
}


void
ball_move()
{
	int	y_cur, x_cur, moved;

	signal( SIGALRM , SIG_IGN );		/* dont get caught now 	*/
	y_cur = the_ball.y_pos ;		/* old spot		*/
	x_cur = the_ball.x_pos ;
	moved = 0 ;

	if ( the_ball.y_ttm > 0 && the_ball.y_ttg-- == 1 ){
		the_ball.y_pos += the_ball.y_dir ;	/* move	*/
		the_ball.y_ttg = the_ball.y_ttm  ;	/* reset*/
		moved = 1;
	}

	if ( the_ball.x_ttm > 0 && the_ball.x_ttg-- == 1 ){
		the_ball.x_pos += the_ball.x_dir ;	/* move	*/
		the_ball.x_ttg = the_ball.x_ttm  ;	/* reset*/
		moved = 1;
	}

	if ( moved ){
		put_a_char( y_cur, x_cur, BLANK );
		put_a_char( the_ball.y_pos, the_ball.x_pos, 
				the_ball.symbol  );
		bounce_or_lose( &the_ball );
		move(23,70);
		refresh();
	}
	signal( SIGALRM, ball_move);		/* for unreliable systems */

}

put_a_char( y, x , c )
char c;
{
	move(y,x);
	addch(c);
}

bounce_or_lose(bp)
struct ppball *bp;
{
	int	return_val = 0 ;

	if ( bp->y_pos == TOP_ROW )
		bp->y_dir = 1 , return_val = 1 ;
	else if ( bp->y_pos == BOT_ROW )
		bp->y_dir = -1 , return_val = 1;

	if ( bp->x_pos == LEFT_EDGE )
		bp->x_dir = 1 , return_val = 1 ;
	else if ( bp->x_pos == RIGHT_EDGE )
		bp->x_dir = -1 , return_val = 1;

	return return_val;
}

