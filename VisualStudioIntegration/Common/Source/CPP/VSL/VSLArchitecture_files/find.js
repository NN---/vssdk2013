
var strShapeName	= "Shape Name";
var strShapeText	= "Shape Text";
var strProps		= "Custom Properties";
var strResults		= "Search results for:";

var strShape	= "Shape Name:";
var strNoCustomPropertiesToDisplayText = "CTRL+click a shape in the drawing to view details.";

var FindShapeXML = parent.FindShapeXML;
var Unquote = parent.Unquote;
var put_Location = parent.put_Location;


var strChkBox		= "Chkbox";
var strPropChkBox	= "PropChkbox";

function doExpando(xxx,yyy){
	if (xxx.style.display=="none"){
		xxx.style.display = ""
		yyy.src = up.src;
	}else{
		xxx.style.display = "none"
		yyy.src = down.src;
	}
}

function doExp(xxx,yyy){
	if (xxx.style.display=="none"){
		xxx.style.display = ""
		yyy.src = "minus.gif";
	}else{
		xxx.style.display = "none"
		yyy.src = "plus.gif";
	}
}


function FindOnClick()
{
	var count, indexOfString;
	
	var fieldsToSearchArray = new Array();
	if (parent.xmlData != null && document.theForm[strProps + strChkBox].checked)
	{
		for( count=0; count < document.theForm.length; count++ )
		{
			indexOfString = document.theForm[count].name.indexOf(strPropChkBox);
			if( -1 != indexOfString && document.theForm[count].checked )
			{
				fieldsToSearchArray[ fieldsToSearchArray.length ] = document.theForm[count].name.slice(0, indexOfString);
			}
		}
	}

	var searchTokensArray = CreateSearchTokens (document.theForm.findString.value);

	if (searchTokensArray.length > 0)
	{
		var findArray = Find(searchTokensArray, fieldsToSearchArray);
		var ArrayLength = findArray.length;
		var strResultsHTML = "No matches found.";
		var lastPageID = null;
		var shapeID;
		
		
		if(ArrayLength > 0)
		{
			strResultsHTML = strResults + ' <b>'+ parent.HTMLEscape(document.theForm.findString.value) +'</b>';
			for ( count = 0; count < ArrayLength; count++)
			{
			
				if( lastPageID != findArray[count].PageID )
				{
					lastPageID = findArray[count].PageID;
				}

				shapeID = findArray[count].ShapeID;
				strResultsHTML += '<p class="results"><a href="javascript:populateSearchResultDetails(\'results_'+ lastPageID +'_'+ shapeID +'\', '+ lastPageID +','+ shapeID +'); TogglePlus(results_' + lastPageID + '_' + shapeID + ',\'img_' + lastPageID + '_' + shapeID + '\', hideResults)"><img src="plus.gif" alt="Shows/hides shape details" width="13" height="9" border="0" id="img_'+ lastPageID +'_'+ shapeID +'"></a>\n'
				strResultsHTML += '<a  class="blu1" href="JavaScript:FindQuerySelect(';

				strResultsHTML += findArray[count].PageID + ",";
				strResultsHTML += findArray[count].ShapeID + ",";
				strResultsHTML += findArray[count].PinX + ",";
				strResultsHTML += findArray[count].PinY;

				strResultsHTML += ')">'+ findArray[count].Title +'</a></p>\n'

				strResultsHTML += '</div>\n';
				strResultsHTML += '<div class="indent" id="results_'+ lastPageID +'_'+ shapeID +'" style="display:none;width:100%;"></div>\n'
			}

		}
		var divAdvSrch = document.all("hideAdvSrch");
		var imgAS0 = document.all("as0");
		
		var tmpObj = document.all("hideResults");
		if( tmpObj != null )
		{
			tmpObj.innerHTML = strResultsHTML;
			tmpObj.open = "true";
			tmpObj.style.display = "block";
		}
	}
}

function CreateSearchTokens (strUserString)
{
	var searchTokensArray = new Array();

	var strToken = "";
	var chCurChar;

	for (var count = 0; count < strUserString.length; count++)
	{
		chCurChar = strUserString.charAt(count);
		if (chCurChar == '"')
		{
			var nNextQuote = strUserString.indexOf('"', count + 1);
			if (nNextQuote >= 0)
			{
				strToken = strUserString.slice(count + 1, nNextQuote);
				searchTokensArray[searchTokensArray.length] = strToken;
				strToken = "";
				count = nNextQuote;
			}
		}
		else if (chCurChar == ' ')
		{
			if (strToken.length > 0)
			{
				searchTokensArray[searchTokensArray.length] = strToken;
			}

			strToken = "";
		}
		else
		{
			strToken += chCurChar;
		}
	}

	if (strToken.length > 0)
	{
		searchTokensArray[searchTokensArray.length] = strToken;
	}

	return searchTokensArray;
}

function populateSearchResultDetails( divID, pageID, shapeID )
{
	var tmpShape = FindShapeXML (pageID, shapeID);
	var strOutput = CreatePropTable( tmpShape );
	
	var tmpObj = document.all(divID);
	if( tmpObj != null )
	{
		tmpObj.innerHTML = strOutput;
	}
}

function makeAdvancedFindCheckboxes(div)
{
	if (parent.xmlData)
	{
		var strOutput = "";

		strOutput += "<INPUT type='checkbox' name='" + strShapeName + strChkBox + "' id='" + strShapeName + strChkBox + "' checked><label for='" + strShapeName + strChkBox + "'>" + strShapeName + "</label><br>\n";
		strOutput += "<INPUT type='checkbox' name='" + strShapeText + strChkBox + "' id='" + strShapeText + strChkBox + "' checked><label for='" + strShapeText + strChkBox + "'>" + strShapeText + "</label><br>\n";
		strOutput += "<INPUT type='checkbox' name='" + strProps + strChkBox + "' id='" + strProps + strChkBox + "' onclick='AdvSearchCustomPropCheck ()'checked ><label for='" + strProps + strChkBox + "'>" + strProps +"</label><br>\n";
		strOutput += "<div id='divCPBoxes' style='margin-left:1em;'>";
		
		var objNodes = parent.xmlData.selectNodes(".//Shape/Prop/Label");
		var filter = "";
		var boolFirstPass = true;
		var tmpPropName;
		while( objNodes.length > 0)
		{
			tmpPropName = objNodes.item( 0 ).text;
			var escapedPropName = parent.EscapeString(tmpPropName);
			if( true == boolFirstPass )
			{
				filter = ". != '" + escapedPropName + "'";
				boolFirstPass = false;
			}
			else
			{
				filter += " and . != '" + escapedPropName + "'";
			}

			tmpPropName = parent.HTMLEscape (tmpPropName);
			strOutput += "<INPUT type='checkbox' name='" + tmpPropName + strPropChkBox + "' id='"+ tmpPropName + strPropChkBox + "' checked><label for='"+ tmpPropName + strPropChkBox + "'>" + tmpPropName +"</label><br>\n";

			objNodes = parent.xmlData.selectNodes(".//Shape/Prop/Label["+ filter + "]");
		}
		strOutput += "</div>"
		div.innerHTML = strOutput;
	}
}

function AdvSearchCustomPropCheck ()
{
	for( count=0; count < document.theForm.length; count++ )
	{
		indexOfString = document.theForm[count].name.indexOf(strPropChkBox);
		if( -1 != indexOfString )
		{
			document.theForm[count].disabled = !document.theForm[strProps + strChkBox].checked;
		}
	}
}


function CResultItem(title, pageID, shapeID, pinX, pinY)
{
	 this["Title"] = title;
	 this["PageID"] = pageID;
	 this["ShapeID"] = shapeID;
	 this["PinX"] = pinX;
	 this["PinY"] = pinY;
}

function FindParentPage(nodeObject)
{
	if(nodeObject == null)
	{
		return null;
	}
	if(nodeObject.baseName == "Page")
		return nodeObject;
	else
		return FindParentPage(nodeObject.parentNode);
}

function QueryStringForMatch(shapeNode, regTextForFind, filterString)
{
	if (filterString.length > 0)
	{
		var nodesToCheck = shapeNode.selectNodes(filterString);

		var nodeCount = nodesToCheck.length;
		var stringToParse;
		for(var ncount = 0; ncount < nodeCount; ncount++)
		{
			stringToParse = nodesToCheck.item(ncount).text;
			stringToParse = stringToParse.toLowerCase ();
			if(stringToParse.indexOf(regTextForFind) > -1)
			{
				return true;
			}
		}
	}
}

function GetShapeTitle(shapeNode)
{
	var objTempName = null;
	var objTempTextElement = shapeNode.selectSingleNode("./Text");
	if(objTempTextElement != null)
	{
		var objTextNode = objTempTextElement.selectSingleNode("textnode()");
		if (objTextNode != null)
		{
			return parent.HTMLEscape (objTextNode.text);
		}
	}

	objTempName = shapeNode.selectSingleNode("./@Name");
	if(objTempName != null)
	{
		return parent.HTMLEscape (objTempName.text);
	}

	return "";
}

function GetPageTitle(pageID)
{
	var pagesObj = parent.xmlData.selectSingleNode("VisioDocument/Pages");
	if(!pagesObj)
	{
		return "";
	}

	var pageQuerryString = './/Page[@ID = "' + pageID + '"]';
	var pageObj = pagesObj.selectSingleNode(pageQuerryString);
	if(!pageObj)
	{
		return "";
	}

	var pageNameNode = pageObj.selectSingleNode("@Name");
	if(!pageNameNode)
	{
		return "";
	}
	return pageNameNode.text;
}

function Find(searchTokensArray, propsToSearchArray)
{
	var bXMLNotValid = false;
	var findArray = new Array();
	var findIndex = 0;

	if (parent.xmlData != null && searchTokensArray.length > 0)
	{
		var fieldsToSearchArray = new Array();
		var filterString = "";
		if( null != propsToSearchArray &&
			propsToSearchArray.length > 0 )
		{
			var propFilterString = "";
			for( var count=0; count< propsToSearchArray.length; count++ )
			{
				if( count == 0 )
				{
					propFilterString = "[. = '" + parent.EscapeString (propsToSearchArray[count]) + "'";
				}
				else
				{
					propFilterString += " or . = '"+ parent.EscapeString (propsToSearchArray[count]) + "'";
				}
			}
			propFilterString += "]";

			fieldsToSearchArray[fieldsToSearchArray.length] = "Prop[Label"+ propFilterString +"]/Value";
		}

		if (document.theForm[strShapeText + strChkBox].checked)
		{
			fieldsToSearchArray[fieldsToSearchArray.length] = "Text";
		}

		if (fieldsToSearchArray.length > 0)
		{
			filterString = "(.//(";

			for (var fieldCount = 0; fieldCount < fieldsToSearchArray.length; fieldCount++)
			{
				if (fieldCount != 0)
				{
					filterString += " | ";
				}

				filterString += fieldsToSearchArray[fieldCount];
			}

			filterString += ")/textnode())";
		}

		var objShapeNodes;

		if (document.theForm[strShapeName + strChkBox].checked)
		{
			if (filterString.length > 0)
			{
				filterString += " | ";
			}
			filterString += "(@Name)";

			var objShapeNodes = parent.xmlData.selectNodes(".//Shape");
		}
		else
		{
			var objShapeNodes = parent.xmlData.selectNodes(".//Shape[(Prop/Value | Prop/Label | Text)]");
		}

		var shapeCount = objShapeNodes.length;
		var objTempData = new CResultItem("A Label","PageID","ShapeID","PinX","PinY");
		var objTempShape = null;

		for (count = 0; count < shapeCount; count++)
		{		
			objTempShape = objShapeNodes.item(count);

			var objParentPageNode = FindParentPage(objTempShape);
			if (objParentPageNode == null)
			{
				continue;
			}

			var objPageIDNode = objParentPageNode.selectSingleNode("@ID/textnode()");
			if(objPageIDNode == null)
			{
				continue;
			}
			var pageID = objPageIDNode.text;

			var pageIndex = parent.PageIndexFromID (pageID);
			if (pageIndex < 0)
			{
				continue;
			}

			var objLayerMember = objTempShape.selectSingleNode("LayerMem/LayerMember");
			if (objLayerMember != null && objLayerMember.text.length > 0)
			{
				var layerArray = objLayerMember.text.split (';');
				var visibleLayer = false;
				for (var layerCount = 0; (layerCount < layerArray.length) && !visibleLayer; layerCount++)
				{
					var objLayerVisible = objParentPageNode.selectSingleNode("Layer[@IX=" + layerArray[layerCount] + "]/Visible");
					if (objLayerVisible != null)
					{
						 visibleLayer = (objLayerVisible.text != 0);
					}
				}
				
				if (!visibleLayer)
				{
					continue;
				}
			}

			for (var tokenCount = 0; tokenCount < searchTokensArray.length; tokenCount++)
			{
				var textToFind = searchTokensArray[tokenCount];
				textToFind = textToFind.toLowerCase ();

				if (QueryStringForMatch(objTempShape, textToFind, filterString))
				{
					objTempData.Title = GetShapeTitle(objTempShape);
					objTempData.PageID = pageID;

					objShapeIDNode = objTempShape.selectSingleNode("@ID/textnode()");
					if(objShapeIDNode == null)
					{
						bXMLNotValid = true;
						break;
					}
					objTempData.ShapeID = objShapeIDNode.text;
					objPinXNode = objTempShape.selectSingleNode("XForm/PinX/textnode()");
					if(objPinXNode == null)
					{
						bXMLNotValid = true;
						break;
					}
					objTempData.PinX = objPinXNode.text;
					objPinYNode = objTempShape.selectSingleNode("XForm/PinY/textnode()");
					if(objPinYNode == null)
					{
						bXMLNotValid = true;
						break;
					}
					objTempData.PinY = objPinYNode.text;

					findArray[findIndex] = new CResultItem(objTempData.Title, objTempData.PageID, objTempData.ShapeID, objTempData.PinX, objTempData.PinY);
					findIndex++;
					break;
				}
			}
		}
		if(bXMLNotValid)
		{
			findArray.length = 0;
		}
	}

	return findArray;
}

function FindQuerySelect(pageID, shapeID, pinX, pinY)
{
	if (widgets.GoTo && (parent.g_FileList[document.all("Select1").value].PageID != pageID))
	{
		parent.g_callBackFunctionArray[parent.g_callBackFunctionArray.length] = function () { parent.viewMgr.put_Location (pageID, shapeID, pinX, pinY); };
		parent.GoToPageByID(pageID);
	}
	else 
	{
		if (parent.viewMgr != null)
		{
			parent.viewMgr.put_Location (pageID, shapeID, pinX, pinY);
		}
	}
}

function TreeSelect(pageID, shapeID)
{
	var shapeNode = FindShapeXML (pageID, shapeID);
	if (shapeNode != null)
	{
		var pinXNode = shapeNode.selectSingleNode("XForm/PinX/textnode()");
		var pinYNode = shapeNode.selectSingleNode("XForm/PinY/textnode()");

		if (pinXNode != null && pinYNode != null)
		{
			FindQuerySelect (pageID, shapeID, pinXNode.text, pinYNode.text);
		}
	}
}


var g_RowStyleList = parent.g_RowStyleList;
var FillPropPane = parent.FillPropPane;
var CreatePropTable = parent.CreatePropTable;


// SIG // Begin signature block
// SIG // MIIalwYJKoZIhvcNAQcCoIIaiDCCGoQCAQExCzAJBgUr
// SIG // DgMCGgUAMGcGCisGAQQBgjcCAQSgWTBXMDIGCisGAQQB
// SIG // gjcCAR4wJAIBAQQQEODJBs441BGiowAQS9NQkAIBAAIB
// SIG // AAIBAAIBAAIBADAhMAkGBSsOAwIaBQAEFAaJ0KyTu99e
// SIG // uEaVCk9qqbqX4zjaoIIVgjCCBMMwggOroAMCAQICEzMA
// SIG // AAAz5SeGow5KKoAAAAAAADMwDQYJKoZIhvcNAQEFBQAw
// SIG // dzELMAkGA1UEBhMCVVMxEzARBgNVBAgTCldhc2hpbmd0
// SIG // b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAcBgNVBAoTFU1p
// SIG // Y3Jvc29mdCBDb3Jwb3JhdGlvbjEhMB8GA1UEAxMYTWlj
// SIG // cm9zb2Z0IFRpbWUtU3RhbXAgUENBMB4XDTEzMDMyNzIw
// SIG // MDgyM1oXDTE0MDYyNzIwMDgyM1owgbMxCzAJBgNVBAYT
// SIG // AlVTMRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQH
// SIG // EwdSZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQgQ29y
// SIG // cG9yYXRpb24xDTALBgNVBAsTBE1PUFIxJzAlBgNVBAsT
// SIG // Hm5DaXBoZXIgRFNFIEVTTjpGNTI4LTM3NzctOEE3NjEl
// SIG // MCMGA1UEAxMcTWljcm9zb2Z0IFRpbWUtU3RhbXAgU2Vy
// SIG // dmljZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoC
// SIG // ggEBAMreyhkPH5ZWgl/YQjLUCG22ncDC7Xw4q1gzrWuB
// SIG // ULiIIQpdr5ctkFrHwy6yTNRjdFj938WJVNALzP2chBF5
// SIG // rKMhIm0z4K7eJUBFkk4NYwgrizfdTwdq3CrPEFqPV12d
// SIG // PfoXYwLGcD67Iu1bsfcyuuRxvHn/+MvpVz90e+byfXxX
// SIG // WC+s0g6o2YjZQB86IkHiCSYCoMzlJc6MZ4PfRviFTcPa
// SIG // Zh7Hc347tHYXpqWgoHRVqOVgGEFiOMdlRqsEFmZW6vmm
// SIG // y0LPXVRkL4H4zzgADxBr4YMujT5I7ElWSuyaafTLDxD7
// SIG // BzRKYmwBjW7HIITKXNFjmR6OXewPpRZIqmveIS8CAwEA
// SIG // AaOCAQkwggEFMB0GA1UdDgQWBBQAWBs+7cXxBpO+MT02
// SIG // tKwLXTLwgTAfBgNVHSMEGDAWgBQjNPjZUkZwCu1A+3b7
// SIG // syuwwzWzDzBUBgNVHR8ETTBLMEmgR6BFhkNodHRwOi8v
// SIG // Y3JsLm1pY3Jvc29mdC5jb20vcGtpL2NybC9wcm9kdWN0
// SIG // cy9NaWNyb3NvZnRUaW1lU3RhbXBQQ0EuY3JsMFgGCCsG
// SIG // AQUFBwEBBEwwSjBIBggrBgEFBQcwAoY8aHR0cDovL3d3
// SIG // dy5taWNyb3NvZnQuY29tL3BraS9jZXJ0cy9NaWNyb3Nv
// SIG // ZnRUaW1lU3RhbXBQQ0EuY3J0MBMGA1UdJQQMMAoGCCsG
// SIG // AQUFBwMIMA0GCSqGSIb3DQEBBQUAA4IBAQAC/+OMA+rv
// SIG // fji5uXyfO1KDpPojONQDuGpZtergb4gD9G9RapU6dYXo
// SIG // HNwHxU6dG6jOJEcUJE81d7GcvCd7j11P/AaLl5f5KZv3
// SIG // QB1SgY52SAN+8psXt67ZWyKRYzsyXzX7xpE8zO8OmYA+
// SIG // BpE4E3oMTL4z27/trUHGfBskfBPcCvxLiiAFHQmJkTkH
// SIG // TiFO3mx8cLur8SCO+Jh4YNyLlM9lvpaQD6CchO1ctXxB
// SIG // oGEtvUNnZRoqgtSniln3MuOj58WNsiK7kijYsIxTj2hH
// SIG // R6HYAbDxYRXEF6Et4zpsT2+vPe7eKbBEy8OSZ7oAzg+O
// SIG // Ee/RAoIxSZSYnVFIeK0d1kC2MIIE7DCCA9SgAwIBAgIT
// SIG // MwAAALARrwqL0Duf3QABAAAAsDANBgkqhkiG9w0BAQUF
// SIG // ADB5MQswCQYDVQQGEwJVUzETMBEGA1UECBMKV2FzaGlu
// SIG // Z3RvbjEQMA4GA1UEBxMHUmVkbW9uZDEeMBwGA1UEChMV
// SIG // TWljcm9zb2Z0IENvcnBvcmF0aW9uMSMwIQYDVQQDExpN
// SIG // aWNyb3NvZnQgQ29kZSBTaWduaW5nIFBDQTAeFw0xMzAx
// SIG // MjQyMjMzMzlaFw0xNDA0MjQyMjMzMzlaMIGDMQswCQYD
// SIG // VQQGEwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4G
// SIG // A1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0
// SIG // IENvcnBvcmF0aW9uMQ0wCwYDVQQLEwRNT1BSMR4wHAYD
// SIG // VQQDExVNaWNyb3NvZnQgQ29ycG9yYXRpb24wggEiMA0G
// SIG // CSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQDor1yiIA34
// SIG // KHy8BXt/re7rdqwoUz8620B9s44z5lc/pVEVNFSlz7SL
// SIG // qT+oN+EtUO01Fk7vTXrbE3aIsCzwWVyp6+HXKXXkG4Un
// SIG // m/P4LZ5BNisLQPu+O7q5XHWTFlJLyjPFN7Dz636o9UEV
// SIG // XAhlHSE38Cy6IgsQsRCddyKFhHxPuRuQsPWj/ov0DJpO
// SIG // oPXJCiHiquMBNkf9L4JqgQP1qTXclFed+0vUDoLbOI8S
// SIG // /uPWenSIZOFixCUuKq6dGB8OHrbCryS0DlC83hyTXEmm
// SIG // ebW22875cHsoAYS4KinPv6kFBeHgD3FN/a1cI4Mp68fF
// SIG // SsjoJ4TTfsZDC5UABbFPZXHFAgMBAAGjggFgMIIBXDAT
// SIG // BgNVHSUEDDAKBggrBgEFBQcDAzAdBgNVHQ4EFgQUWXGm
// SIG // WjNN2pgHgP+EHr6H+XIyQfIwUQYDVR0RBEowSKRGMEQx
// SIG // DTALBgNVBAsTBE1PUFIxMzAxBgNVBAUTKjMxNTk1KzRm
// SIG // YWYwYjcxLWFkMzctNGFhMy1hNjcxLTc2YmMwNTIzNDRh
// SIG // ZDAfBgNVHSMEGDAWgBTLEejK0rQWWAHJNy4zFha5TJoK
// SIG // HzBWBgNVHR8ETzBNMEugSaBHhkVodHRwOi8vY3JsLm1p
// SIG // Y3Jvc29mdC5jb20vcGtpL2NybC9wcm9kdWN0cy9NaWND
// SIG // b2RTaWdQQ0FfMDgtMzEtMjAxMC5jcmwwWgYIKwYBBQUH
// SIG // AQEETjBMMEoGCCsGAQUFBzAChj5odHRwOi8vd3d3Lm1p
// SIG // Y3Jvc29mdC5jb20vcGtpL2NlcnRzL01pY0NvZFNpZ1BD
// SIG // QV8wOC0zMS0yMDEwLmNydDANBgkqhkiG9w0BAQUFAAOC
// SIG // AQEAMdduKhJXM4HVncbr+TrURE0Inu5e32pbt3nPApy8
// SIG // dmiekKGcC8N/oozxTbqVOfsN4OGb9F0kDxuNiBU6fNut
// SIG // zrPJbLo5LEV9JBFUJjANDf9H6gMH5eRmXSx7nR2pEPoc
// SIG // sHTyT2lrnqkkhNrtlqDfc6TvahqsS2Ke8XzAFH9IzU2y
// SIG // RPnwPJNtQtjofOYXoJtoaAko+QKX7xEDumdSrcHps3Om
// SIG // 0mPNSuI+5PNO/f+h4LsCEztdIN5VP6OukEAxOHUoXgSp
// SIG // Rm3m9Xp5QL0fzehF1a7iXT71dcfmZmNgzNWahIeNJDD3
// SIG // 7zTQYx2xQmdKDku/Og7vtpU6pzjkJZIIpohmgjCCBbww
// SIG // ggOkoAMCAQICCmEzJhoAAAAAADEwDQYJKoZIhvcNAQEF
// SIG // BQAwXzETMBEGCgmSJomT8ixkARkWA2NvbTEZMBcGCgmS
// SIG // JomT8ixkARkWCW1pY3Jvc29mdDEtMCsGA1UEAxMkTWlj
// SIG // cm9zb2Z0IFJvb3QgQ2VydGlmaWNhdGUgQXV0aG9yaXR5
// SIG // MB4XDTEwMDgzMTIyMTkzMloXDTIwMDgzMTIyMjkzMlow
// SIG // eTELMAkGA1UEBhMCVVMxEzARBgNVBAgTCldhc2hpbmd0
// SIG // b24xEDAOBgNVBAcTB1JlZG1vbmQxHjAcBgNVBAoTFU1p
// SIG // Y3Jvc29mdCBDb3Jwb3JhdGlvbjEjMCEGA1UEAxMaTWlj
// SIG // cm9zb2Z0IENvZGUgU2lnbmluZyBQQ0EwggEiMA0GCSqG
// SIG // SIb3DQEBAQUAA4IBDwAwggEKAoIBAQCycllcGTBkvx2a
// SIG // YCAgQpl2U2w+G9ZvzMvx6mv+lxYQ4N86dIMaty+gMuz/
// SIG // 3sJCTiPVcgDbNVcKicquIEn08GisTUuNpb15S3GbRwfa
// SIG // /SXfnXWIz6pzRH/XgdvzvfI2pMlcRdyvrT3gKGiXGqel
// SIG // cnNW8ReU5P01lHKg1nZfHndFg4U4FtBzWwW6Z1KNpbJp
// SIG // L9oZC/6SdCnidi9U3RQwWfjSjWL9y8lfRjFQuScT5EAw
// SIG // z3IpECgixzdOPaAyPZDNoTgGhVxOVoIoKgUyt0vXT2Pn
// SIG // 0i1i8UU956wIAPZGoZ7RW4wmU+h6qkryRs83PDietHdc
// SIG // pReejcsRj1Y8wawJXwPTAgMBAAGjggFeMIIBWjAPBgNV
// SIG // HRMBAf8EBTADAQH/MB0GA1UdDgQWBBTLEejK0rQWWAHJ
// SIG // Ny4zFha5TJoKHzALBgNVHQ8EBAMCAYYwEgYJKwYBBAGC
// SIG // NxUBBAUCAwEAATAjBgkrBgEEAYI3FQIEFgQU/dExTtMm
// SIG // ipXhmGA7qDFvpjy82C0wGQYJKwYBBAGCNxQCBAweCgBT
// SIG // AHUAYgBDAEEwHwYDVR0jBBgwFoAUDqyCYEBWJ5flJRP8
// SIG // KuEKU5VZ5KQwUAYDVR0fBEkwRzBFoEOgQYY/aHR0cDov
// SIG // L2NybC5taWNyb3NvZnQuY29tL3BraS9jcmwvcHJvZHVj
// SIG // dHMvbWljcm9zb2Z0cm9vdGNlcnQuY3JsMFQGCCsGAQUF
// SIG // BwEBBEgwRjBEBggrBgEFBQcwAoY4aHR0cDovL3d3dy5t
// SIG // aWNyb3NvZnQuY29tL3BraS9jZXJ0cy9NaWNyb3NvZnRS
// SIG // b290Q2VydC5jcnQwDQYJKoZIhvcNAQEFBQADggIBAFk5
// SIG // Pn8mRq/rb0CxMrVq6w4vbqhJ9+tfde1MOy3XQ60L/svp
// SIG // LTGjI8x8UJiAIV2sPS9MuqKoVpzjcLu4tPh5tUly9z7q
// SIG // QX/K4QwXaculnCAt+gtQxFbNLeNK0rxw56gNogOlVuC4
// SIG // iktX8pVCnPHz7+7jhh80PLhWmvBTI4UqpIIck+KUBx3y
// SIG // 4k74jKHK6BOlkU7IG9KPcpUqcW2bGvgc8FPWZ8wi/1wd
// SIG // zaKMvSeyeWNWRKJRzfnpo1hW3ZsCRUQvX/TartSCMm78
// SIG // pJUT5Otp56miLL7IKxAOZY6Z2/Wi+hImCWU4lPF6H0q7
// SIG // 0eFW6NB4lhhcyTUWX92THUmOLb6tNEQc7hAVGgBd3TVb
// SIG // Ic6YxwnuhQ6MT20OE049fClInHLR82zKwexwo1eSV32U
// SIG // jaAbSANa98+jZwp0pTbtLS8XyOZyNxL0b7E8Z4L5UrKN
// SIG // MxZlHg6K3RDeZPRvzkbU0xfpecQEtNP7LN8fip6sCvsT
// SIG // J0Ct5PnhqX9GuwdgR2VgQE6wQuxO7bN2edgKNAltHIAx
// SIG // H+IOVN3lofvlRxCtZJj/UBYufL8FIXrilUEnacOTj5XJ
// SIG // jdibIa4NXJzwoq6GaIMMai27dmsAHZat8hZ79haDJLmI
// SIG // z2qoRzEvmtzjcT3XAH5iR9HOiMm4GPoOco3Boz2vAkBq
// SIG // /2mbluIQqBC0N1AI1sM9MIIGBzCCA++gAwIBAgIKYRZo
// SIG // NAAAAAAAHDANBgkqhkiG9w0BAQUFADBfMRMwEQYKCZIm
// SIG // iZPyLGQBGRYDY29tMRkwFwYKCZImiZPyLGQBGRYJbWlj
// SIG // cm9zb2Z0MS0wKwYDVQQDEyRNaWNyb3NvZnQgUm9vdCBD
// SIG // ZXJ0aWZpY2F0ZSBBdXRob3JpdHkwHhcNMDcwNDAzMTI1
// SIG // MzA5WhcNMjEwNDAzMTMwMzA5WjB3MQswCQYDVQQGEwJV
// SIG // UzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4GA1UEBxMH
// SIG // UmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0IENvcnBv
// SIG // cmF0aW9uMSEwHwYDVQQDExhNaWNyb3NvZnQgVGltZS1T
// SIG // dGFtcCBQQ0EwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAw
// SIG // ggEKAoIBAQCfoWyx39tIkip8ay4Z4b3i48WZUSNQrc7d
// SIG // GE4kD+7Rp9FMrXQwIBHrB9VUlRVJlBtCkq6YXDAm2gBr
// SIG // 6Hu97IkHD/cOBJjwicwfyzMkh53y9GccLPx754gd6udO
// SIG // o6HBI1PKjfpFzwnQXq/QsEIEovmmbJNn1yjcRlOwhtDl
// SIG // KEYuJ6yGT1VSDOQDLPtqkJAwbofzWTCd+n7Wl7PoIZd+
// SIG // +NIT8wi3U21StEWQn0gASkdmEScpZqiX5NMGgUqi+YSn
// SIG // EUcUCYKfhO1VeP4Bmh1QCIUAEDBG7bfeI0a7xC1Un68e
// SIG // eEExd8yb3zuDk6FhArUdDbH895uyAc4iS1T/+QXDwiAL
// SIG // AgMBAAGjggGrMIIBpzAPBgNVHRMBAf8EBTADAQH/MB0G
// SIG // A1UdDgQWBBQjNPjZUkZwCu1A+3b7syuwwzWzDzALBgNV
// SIG // HQ8EBAMCAYYwEAYJKwYBBAGCNxUBBAMCAQAwgZgGA1Ud
// SIG // IwSBkDCBjYAUDqyCYEBWJ5flJRP8KuEKU5VZ5KShY6Rh
// SIG // MF8xEzARBgoJkiaJk/IsZAEZFgNjb20xGTAXBgoJkiaJ
// SIG // k/IsZAEZFgltaWNyb3NvZnQxLTArBgNVBAMTJE1pY3Jv
// SIG // c29mdCBSb290IENlcnRpZmljYXRlIEF1dGhvcml0eYIQ
// SIG // ea0WoUqgpa1Mc1j0BxMuZTBQBgNVHR8ESTBHMEWgQ6BB
// SIG // hj9odHRwOi8vY3JsLm1pY3Jvc29mdC5jb20vcGtpL2Ny
// SIG // bC9wcm9kdWN0cy9taWNyb3NvZnRyb290Y2VydC5jcmww
// SIG // VAYIKwYBBQUHAQEESDBGMEQGCCsGAQUFBzAChjhodHRw
// SIG // Oi8vd3d3Lm1pY3Jvc29mdC5jb20vcGtpL2NlcnRzL01p
// SIG // Y3Jvc29mdFJvb3RDZXJ0LmNydDATBgNVHSUEDDAKBggr
// SIG // BgEFBQcDCDANBgkqhkiG9w0BAQUFAAOCAgEAEJeKw1wD
// SIG // RDbd6bStd9vOeVFNAbEudHFbbQwTq86+e4+4LtQSooxt
// SIG // YrhXAstOIBNQmd16QOJXu69YmhzhHQGGrLt48ovQ7DsB
// SIG // 7uK+jwoFyI1I4vBTFd1Pq5Lk541q1YDB5pTyBi+FA+mR
// SIG // KiQicPv2/OR4mS4N9wficLwYTp2OawpylbihOZxnLcVR
// SIG // DupiXD8WmIsgP+IHGjL5zDFKdjE9K3ILyOpwPf+FChPf
// SIG // wgphjvDXuBfrTot/xTUrXqO/67x9C0J71FNyIe4wyrt4
// SIG // ZVxbARcKFA7S2hSY9Ty5ZlizLS/n+YWGzFFW6J1wlGys
// SIG // OUzU9nm/qhh6YinvopspNAZ3GmLJPR5tH4LwC8csu89D
// SIG // s+X57H2146SodDW4TsVxIxImdgs8UoxxWkZDFLyzs7BN
// SIG // Z8ifQv+AeSGAnhUwZuhCEl4ayJ4iIdBD6Svpu/RIzCzU
// SIG // 2DKATCYqSCRfWupW76bemZ3KOm+9gSd0BhHudiG/m4LB
// SIG // J1S2sWo9iaF2YbRuoROmv6pH8BJv/YoybLL+31HIjCPJ
// SIG // Zr2dHYcSZAI9La9Zj7jkIeW1sMpjtHhUBdRBLlCslLCl
// SIG // eKuzoJZ1GtmShxN1Ii8yqAhuoFuMJb+g74TKIdbrHk/J
// SIG // mu5J4PcBZW+JC33Iacjmbuqnl84xKf8OxVtc2E0bodj6
// SIG // L54/LlUWa8kTo/0xggSBMIIEfQIBATCBkDB5MQswCQYD
// SIG // VQQGEwJVUzETMBEGA1UECBMKV2FzaGluZ3RvbjEQMA4G
// SIG // A1UEBxMHUmVkbW9uZDEeMBwGA1UEChMVTWljcm9zb2Z0
// SIG // IENvcnBvcmF0aW9uMSMwIQYDVQQDExpNaWNyb3NvZnQg
// SIG // Q29kZSBTaWduaW5nIFBDQQITMwAAALARrwqL0Duf3QAB
// SIG // AAAAsDAJBgUrDgMCGgUAoIGaMBkGCSqGSIb3DQEJAzEM
// SIG // BgorBgEEAYI3AgEEMBwGCisGAQQBgjcCAQsxDjAMBgor
// SIG // BgEEAYI3AgEVMCMGCSqGSIb3DQEJBDEWBBTZReX2O+Gl
// SIG // UbtFJX7AkZYRAHjMFzA6BgorBgEEAYI3AgEMMSwwKqAQ
// SIG // gA4AZgBpAG4AZAAuAGoAc6EWgBRodHRwOi8vbWljcm9z
// SIG // b2Z0LmNvbTANBgkqhkiG9w0BAQEFAASCAQDKMh8hdk6Q
// SIG // 7eZLYfSXtOouxsy9NJ84zLjFRO+Grs0CAUagWUifkLcf
// SIG // dDk6XYNTGGz0RzMKn5MnmBncbcGrWs6ym1r8xQlt1oaY
// SIG // HMTsbXl7VAikAapAGOwDwvhpCNnkkh4OTJR4OIq1CS9u
// SIG // 8iSmvFFgJP88PN+2qufjj7OKodimlILyXyzbEJki+kyr
// SIG // nfD4vmvLviux9blORHbCsyXq76D7NPu6NWBNN5o0Qvne
// SIG // Hb6zATonzBln/rzL99Rcyrj3V/4ixTPTrPVnk9fYt2S/
// SIG // 50s9T/n8QpLLDlrWlGmMAxyc/Mis77uSZfUH4zeO5YHC
// SIG // k6LJGX3VjZKMHKGG+6U4HdFuoYICKDCCAiQGCSqGSIb3
// SIG // DQEJBjGCAhUwggIRAgEBMIGOMHcxCzAJBgNVBAYTAlVT
// SIG // MRMwEQYDVQQIEwpXYXNoaW5ndG9uMRAwDgYDVQQHEwdS
// SIG // ZWRtb25kMR4wHAYDVQQKExVNaWNyb3NvZnQgQ29ycG9y
// SIG // YXRpb24xITAfBgNVBAMTGE1pY3Jvc29mdCBUaW1lLVN0
// SIG // YW1wIFBDQQITMwAAADPlJ4ajDkoqgAAAAAAAMzAJBgUr
// SIG // DgMCGgUAoF0wGAYJKoZIhvcNAQkDMQsGCSqGSIb3DQEH
// SIG // ATAcBgkqhkiG9w0BCQUxDxcNMTMwODI3MTcyMTEwWjAj
// SIG // BgkqhkiG9w0BCQQxFgQUFzzkH2ZVdWL2SEf8ff9zpCpp
// SIG // 9X4wDQYJKoZIhvcNAQEFBQAEggEArERE0zm/ocsh8msm
// SIG // affNCl2Ll0GMPXnXsUROknZJKVMlZRlcs3zj/RaUcbxE
// SIG // GcmxEYhaosVDaUeKvK/99w3RI5216dQ2vkvqgkeBcXOJ
// SIG // KL+eo+pn7yu5i+WMWex18cIlhVP7sVR0kIQRGzYvCKus
// SIG // NIH+BDBpy0ZhaXXWb7lwOx2sECWnRkSAZCXiPhKPEd5W
// SIG // XVrbnb4Ku7gFiDbVF67NTj3g0AhOEQLijr+b0+vjiQOI
// SIG // ydWzDBTVzramAqXspXgwzukK4Cyq+1wxPdO2j2tl4ruW
// SIG // V+urWnNW9hnvL+JC44pUtCRRGe945opJEsKUaGYJCN53
// SIG // 1bTn6Hq/lnpDCmOkSQ==
// SIG // End signature block
