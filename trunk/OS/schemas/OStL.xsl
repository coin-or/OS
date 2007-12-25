<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:os="os.optimizationservices.org" exclude-result-prefixes="os">
	<xsl:output method="html" version="1.0" encoding="UTF-8" indent="yes"/>
	<xsl:template match="/">
		<html>
			<body>
				<h1>No title</h1>
				<b>objective: </b><xsl:value-of select="/os:OSrL/os:result/os:objective/os:objectiveValue/@value"/><p/>
				<table>
					<td colspan="2" align="center">
						<b>Variable Solutions</b>
						<table border="2" width="10">
							<tr><td><b>variable</b>	</td><td><b>solution</b></td></tr>
							<xsl:for-each select="/os:OSrL/os:result/os:variables/os:variableSolution/os:var">
								<tr>
									<td><xsl:value-of select="@varName"/></td>
									<td><xsl:value-of select="@value"/></td>
								</tr>
							</xsl:for-each>
						</table>
					</td>
				</table>
				<table>
					<td colspan="2" align="center">
						<b>Constraint Values</b>
						<table border="2" width="10">
							<tr><td><b>constraint</b></td><td><b>value</b></td></tr>
							<xsl:for-each select="/os:OSrL/os:result/os:constraints/os:constraintValue/os:con">
								<tr>
									<td><xsl:value-of select="@conName"/></td>
									<td><xsl:value-of select="@value"/></td>
								</tr>
							</xsl:for-each>
						</table>
					</td>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>
