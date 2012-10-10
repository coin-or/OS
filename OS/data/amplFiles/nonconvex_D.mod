#
# A nonconvex problem
#
# Source: Anderson, Sweeney, Williams, Camm, and Martin, 13th ed.

var x >=-10, <=10, integer;
var y >=-10, <=10, integer;

s.t. con: -10 <= x + y                    <= 10;

minimize obj:  ( 3.0*(1-x)**2 * exp(-(x**2+(y+1)**2)))
             - (10.0*(x/5 + x**3 + y**5)*(exp(-(x**2+y**2))) )
             - 1*(exp(-((x+1)**2+(y)**2))/3.0);

#	<nonlinearExpressions numberOfNonlinearExpressions="1">
#		<nl idx="-1">
#			<sum>
#				<product>
#					<number type="real" value="3.0"/>
#					<square>
#						<minus>
#							<number type="real" value="1.0"/>
#							<variable coef="1.0" idx="0"/>
#						</minus>
#					</square>
#					<exp>
#						<negate>
#							<plus>
#								<square>
#									<variable coef="1.0" idx="0"/>
#								</square>
#								<square>
#									<sum>
#										<variable coef="1.0" idx="1"/>
#										<number type="real" value="1.0"/>
#									</sum>
#								</square>
#							</plus>
#						</negate>
#					</exp>
#				</product>
#					
#					
#				<product>
#					<number type="real" value="-10.0"/>
#					<sum>
#						<divide>
#							<variable coef="1.0" idx="0"/>
#							<number type="real" value="5.0"/>
#						</divide>
#						<negate>
#							<power>
#								<variable coef="1.0" idx="0"/>
#								<number type="real" value="3.0"/>
#							</power>
#						</negate>
#						<negate>
#							<power>
#								<variable coef="1.0" idx="1"/>
#								<number type="real" value="5.0"/>
#							</power>
#						</negate>
#					</sum>
#					<exp>
#						<negate>
#							<plus>
#								<square>
#									<variable coef="1.0" idx="0"/>
#								</square>
#								<square>
#									<variable coef="1.0" idx="1"/>
#								</square>
#							</plus>
#						</negate>
#					</exp>
#				</product>
#					
#					
#				<times>
#					<number type="real" value="-1"/>
#					<divide>
#						<exp>
#							<negate>
#								<plus>
#									<square>
#										<sum>
#											<variable coef="1.0" idx="0"/>
#											<number type="real" value="1.0"/>
#										</sum>
#									</square>
#									<square>
#										<variable coef="1.0" idx="1"/>
#									</square>
#								</plus>
#							</negate>
#						</exp>
#						<number type="real" value="3.0"/>
#					</divide>
#				</times>
#			</sum>
#		</nl>
#	</nonlinearExpressions>
					

