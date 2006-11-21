/**
 * ASMXTestServiceLocator.java
 *
 * This file was auto-generated from WSDL
 * by the Apache Axis 1.2.1 Jun 14, 2005 (09:15:57 EDT) WSDL2Java emitter.
 */

package ossolver.optimizationservices.org;

public class ASMXTestServiceLocator extends org.apache.axis.client.Service implements ossolver.optimizationservices.org.ASMXTestService {

    public ASMXTestServiceLocator() {
    }


    public ASMXTestServiceLocator(org.apache.axis.EngineConfiguration config) {
        super(config);
    }

    public ASMXTestServiceLocator(java.lang.String wsdlLoc, javax.xml.namespace.QName sName) throws javax.xml.rpc.ServiceException {
        super(wsdlLoc, sName);
    }

    // Use to get a proxy class for ASMXTestServiceSoap
    private java.lang.String ASMXTestServiceSoap_address = "http://localhost/OSSolver/ASMXTestService.asmx";

    public java.lang.String getASMXTestServiceSoapAddress() {
        return ASMXTestServiceSoap_address;
    }

    // The WSDD service name defaults to the port name.
    private java.lang.String ASMXTestServiceSoapWSDDServiceName = "ASMXTestServiceSoap";

    public java.lang.String getASMXTestServiceSoapWSDDServiceName() {
        return ASMXTestServiceSoapWSDDServiceName;
    }

    public void setASMXTestServiceSoapWSDDServiceName(java.lang.String name) {
        ASMXTestServiceSoapWSDDServiceName = name;
    }

    public ossolver.optimizationservices.org.ASMXTestServiceSoap getASMXTestServiceSoap() throws javax.xml.rpc.ServiceException {
       java.net.URL endpoint;
        try {
            endpoint = new java.net.URL(ASMXTestServiceSoap_address);
        }
        catch (java.net.MalformedURLException e) {
            throw new javax.xml.rpc.ServiceException(e);
        }
        return getASMXTestServiceSoap(endpoint);
    }

    public ossolver.optimizationservices.org.ASMXTestServiceSoap getASMXTestServiceSoap(java.net.URL portAddress) throws javax.xml.rpc.ServiceException {
        try {
            ossolver.optimizationservices.org.ASMXTestServiceSoapStub _stub = new ossolver.optimizationservices.org.ASMXTestServiceSoapStub(portAddress, this);
            _stub.setPortName(getASMXTestServiceSoapWSDDServiceName());
            return _stub;
        }
        catch (org.apache.axis.AxisFault e) {
            return null;
        }
    }

    public void setASMXTestServiceSoapEndpointAddress(java.lang.String address) {
        ASMXTestServiceSoap_address = address;
    }

    /**
     * For the given interface, get the stub implementation.
     * If this service has no port for the given interface,
     * then ServiceException is thrown.
     */
    public java.rmi.Remote getPort(Class serviceEndpointInterface) throws javax.xml.rpc.ServiceException {
        try {
            if (ossolver.optimizationservices.org.ASMXTestServiceSoap.class.isAssignableFrom(serviceEndpointInterface)) {
                ossolver.optimizationservices.org.ASMXTestServiceSoapStub _stub = new ossolver.optimizationservices.org.ASMXTestServiceSoapStub(new java.net.URL(ASMXTestServiceSoap_address), this);
                _stub.setPortName(getASMXTestServiceSoapWSDDServiceName());
                return _stub;
            }
        }
        catch (java.lang.Throwable t) {
            throw new javax.xml.rpc.ServiceException(t);
        }
        throw new javax.xml.rpc.ServiceException("There is no stub implementation for the interface:  " + (serviceEndpointInterface == null ? "null" : serviceEndpointInterface.getName()));
    }

    /**
     * For the given interface, get the stub implementation.
     * If this service has no port for the given interface,
     * then ServiceException is thrown.
     */
    public java.rmi.Remote getPort(javax.xml.namespace.QName portName, Class serviceEndpointInterface) throws javax.xml.rpc.ServiceException {
        if (portName == null) {
            return getPort(serviceEndpointInterface);
        }
        java.lang.String inputPortName = portName.getLocalPart();
        if ("ASMXTestServiceSoap".equals(inputPortName)) {
            return getASMXTestServiceSoap();
        }
        else  {
            java.rmi.Remote _stub = getPort(serviceEndpointInterface);
            ((org.apache.axis.client.Stub) _stub).setPortName(portName);
            return _stub;
        }
    }

    public javax.xml.namespace.QName getServiceName() {
        return new javax.xml.namespace.QName("org.optimizationservices.ossolver", "ASMXTestService");
    }

    private java.util.HashSet ports = null;

    public java.util.Iterator getPorts() {
        if (ports == null) {
            ports = new java.util.HashSet();
            ports.add(new javax.xml.namespace.QName("org.optimizationservices.ossolver", "ASMXTestServiceSoap"));
        }
        return ports.iterator();
    }

    /**
    * Set the endpoint address for the specified port name.
    */
    public void setEndpointAddress(java.lang.String portName, java.lang.String address) throws javax.xml.rpc.ServiceException {
        
if ("ASMXTestServiceSoap".equals(portName)) {
            setASMXTestServiceSoapEndpointAddress(address);
        }
        else 
{ // Unknown Port Name
            throw new javax.xml.rpc.ServiceException(" Cannot set Endpoint Address for Unknown Port" + portName);
        }
    }

    /**
    * Set the endpoint address for the specified port name.
    */
    public void setEndpointAddress(javax.xml.namespace.QName portName, java.lang.String address) throws javax.xml.rpc.ServiceException {
        setEndpointAddress(portName.getLocalPart(), address);
    }

}
