# include "ipopt_cppad_nlp.hpp"

class FG_info : public ipopt_cppad_fg_info
{
public:
	ADVector eval_r(size_t k, const ADVector&  x)
	{	ADVector fg(3);
		// f(x)
		fg[0] = x[0] * x[3] * (x[0] + x[1] + x[2]) + x[2];
		// g_1 (x)
		fg[1] = x[0] * x[1] * x[2] * x[3];
		// g_2 (x)
		fg[2] = x[0] * x[0] + x[1] * x[1] + x[2] * x[2] + x[3] * x[3];
		return fg;
	}
	bool retape(size_t k)
	{	return false; }
};

int main(void)
{	size_t n = 4, m = 2, j;
	NumberVector x_i(n), x_l(n), x_u(n);
	for(j = 0; j < n; j++)
	{	x_l[j] = 1.0; 
		x_i[j] = 3.0; 
		x_u[j] = 5.0; 
	}
	NumberVector g_l(m), g_u(m);
	g_l[0] = 25.0;     g_l[1] = 40.0;
        g_u[0] = 1.0e19;   g_u[1] = 40.0;


	using Ipopt::SmartPtr; 
	using Ipopt::TNLP;

	// create the CppAD interface to Ipopt
	FG_info fg_info;
	ipopt_cppad_solution solve;
	SmartPtr<TNLP> cppad_nlp = new ipopt_cppad_nlp
		(n, m, x_i, x_l, x_u, g_l, g_u, &fg_info, &solve);

	SmartPtr<Ipopt::IpoptApplication> app = new Ipopt::IpoptApplication();
	app->Options()->SetIntegerValue("print_level", -2);
	app->Initialize();
	app->OptimizeTNLP(cppad_nlp);

	std::cout << "solve.x = " << solve.x << std::endl;

	return 0;
}
