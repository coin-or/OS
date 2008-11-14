<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:dw="http://FML/lpfml.xsd" exclude-result-prefixes="dw">
	<xsl:output method="html"/>
	<xsl:template match="/">
		<html>
			<head>
				<link rel="stylesheet" href="doowop.css"/>
			</head>
			<body>
				<h1>Linear Program Solution</h1>
				<xsl:value-of select="/dw:mathProgram/@xmlns"/>
				<table>
					<td colspan="2" align="center">
						<b>PRIMAL SOLUTION  </b>
						<table border="2" width="10">
							<tr>
								<td>
									<b>Variable</b>
								</td>
								<td>
									<b>Value</b>
								</td>
							</tr>
							<xsl:for-each select="/dw:mathProgram/dw:linearProgramSolution/dw:primalSolution/dw:sol">
								<tr>
									<td>
										<xsl:value-of select="@name"/>
									</td>
									<td>
										<xsl:value-of select="@val"/>
									</td>
								</tr>
							</xsl:for-each>
						</table>
					</td>
					<td>
						<table width="10">
</table>
					</td>
					<td colspan="2" align="center">
						<b>DUAL SOLUTION</b>
						<table border="2">
							<tr>
								<td>
									<b>Constraint</b>
								</td>
								<td>
									<b>Dual Value</b>
								</td>
							</tr>
							<xsl:for-each select="/dw:mathProgram/dw:linearProgramSolution/dw:dualSolution/dw:sol">
								<tr>
									<td>
										<xsl:value-of select="@name"/>
									</td>
									<td>
										<xsl:value-of select="@val"/>
									</td>
								</tr>
							</xsl:for-each>
						</table>
					</td>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
